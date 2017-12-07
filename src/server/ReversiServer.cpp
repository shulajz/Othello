//
// Created by or on 12/4/17.
//

#include "ReversiServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_CONNECTED_CLIENTS 2

ReversiServer::ReversiServer(int port): port(port), serverSocket(0) ,receiveMove(false){
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
        stop();
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress1;
    socklen_t clientAddressLen1;
    struct sockaddr_in clientAddress2;
    socklen_t clientAddressLen2;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket1 = accept(serverSocket, (struct
                sockaddr *)&clientAddress1, &clientAddressLen1);
        cout << "Client connected1" << endl;
        if (clientSocket1 == -1){
            stop();
            throw "Error on accept";
        }
        //accept client 2
        int clientSocket2 = accept(serverSocket, (struct
                sockaddr *)&clientAddress2, &clientAddressLen2);
        cout << "Client connected2" << endl;
        if (clientSocket2 == -1) {
            stop();
            throw "Error on accept";
        }
        sendValueOfClient(clientSocket1,clientSocket2);
        int count=0;
        while(count<=10000){
            handleClient(clientSocket1, clientSocket2);
            handleClient(clientSocket2, clientSocket1);
            count++;
        }
        // Close communication with the client
        close(clientSocket1);
        close(clientSocket2);
    }
}

void ReversiServer::handleClient(int clientSocket1, int clientSocket2) {
    int row = 0;
    int col = 0;

    int n = read(clientSocket1, &row, sizeof(row));
    if (n == -1) {
        cout << "Error reading row" << endl;
        return;
    }

    n = read(clientSocket1, &col, sizeof(col));
    if (n == -1) {
        cout << "Error reading row" << endl;
        return;
    }

    cout << "Got Move: row: " << row << " col: " << col << endl;

    int moveToSendToOtherClient[2];
    moveToSendToOtherClient[0] = row;
    moveToSendToOtherClient[1] = col;
    n = write(clientSocket2, &moveToSendToOtherClient, sizeof(moveToSendToOtherClient));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }

}
void ReversiServer::stop() {
    close(serverSocket);
}

void ReversiServer::sendValueOfClient(int clientSocket1, int clientSocket2) {
    char player1 = '1';
    char player2 = '2';
    int n = write(clientSocket1, &player1, sizeof(player1));
    cout << "Write on ClientSocket1" << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
    n = write(clientSocket2, &player2, sizeof(player2));
    cout << "Write on ClientSocket2" << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}
