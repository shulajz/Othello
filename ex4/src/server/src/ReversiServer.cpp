//
// Created by or on 12/4/17.
//

#include "ReversiServer.h"
#include "HandleClientReversi.h"
#include <pthread.h>

#define MAX_CONNECTED_CLIENTS 50

ReversiServer::ReversiServer(int port, HandleClientReversi &handleClientReversi):
        port(port), serverSocket(0), 
        stopServer(false), pool(THREADS_NUM),
        m_handleClient(handleClientReversi){

    cout << "Server" << endl;
}

void ReversiServer::getCloseFromUser() {
    while(true) {
        string select;
        cin >> select;
        if (select == "exit"){
            break;
        }
        cin.clear();
    }
    m_handleClient.sendCloseToEveryOne();
    stopServer = true;
    stop();
}

void* ReversiServer :: gateFunctionServer(void* element) {
        ReversiServer* server = (ReversiServer*)element;
        try{
            server->serverFunc();
        }catch (const char *msg) {
            cout << "Cannot start server. Reason: " << msg << endl;
            exit(-1);
        }

}

void ReversiServer::start() {
    pthread_t thread1;
    int rc = pthread_create(&thread1, NULL, gateFunctionServer, this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
    }
    getCloseFromUser();
}

void ReversiServer::serverFunc(){
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,
          sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress1;
    socklen_t clientAddressLen1;
    while (!stopServer) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddress1, &clientAddressLen1);
        ClientData* clientData = new ClientData();
        clientData->clientSocket = clientSocket;
        clientData->handleClient = &m_handleClient;
        Task *task = new Task(HandleClientReversi :: gateFunction, (void*)clientData);
        pool.addTask(task);
//        m_handleClient.run(clientSocket);
        
    }
}


void ReversiServer::stop() {
    cout << "close server" << endl;
    pool.terminate();
    //pthread cancel serverthreadID?
    close(serverSocket);
}