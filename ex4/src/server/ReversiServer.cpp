//
// Created by or on 12/4/17.
//;

#include "ReversiServer.h"
#include "HandleClient.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <sstream>

#define MAX_CONNECTED_CLIENTS 50

ReversiServer::ReversiServer(int port): port(port),
                                        serverSocket(0){
    // Init mutex

    cout << "Server" << endl;
}
void ReversiServer::start() {
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
    pthread_t thread;
    HandleClient handleClient;
    while (true) {

        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddress1, &clientAddressLen1);

        handleClient.run(clientSocket, thread);
    }
}


void ReversiServer::stop() {
    cout << "close server" << endl;
    close(serverSocket);
}
