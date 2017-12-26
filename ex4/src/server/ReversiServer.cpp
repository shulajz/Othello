//
// Created by or on 12/4/17.
//;

#include "ReversiServer.h"
#include "HandleClient.h"

#define MAX_CONNECTED_CLIENTS 50

ReversiServer::ReversiServer(int port): port(port),
                                        serverSocket(0){
    // Init mutex
    cout << "Server" << endl;
}

void ReversiServer::getClose() {
//    ClientData* data = (ClientData*)element;

}
void* ReversiServer :: gateFunction(void* element) {
        ReversiServer* server = (ReversiServer*)element;
        server->getClose();

}

void ReversiServer::start() {
        pthread_t thread1;
        //create thread that handle with the commands,
        // and after read command and execute it, the thread will ended.
        int rc = pthread_create(&thread1, NULL, gateFunction, this);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }

    ///////////*********************************////////////////////////////////
    // Create a socket point
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
    HandleClient handleClient;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddress1, &clientAddressLen1);
        handleClient.run(clientSocket);
    }
}


void ReversiServer::stop() {
    cout << "close server" << endl;
    close(serverSocket);
}
