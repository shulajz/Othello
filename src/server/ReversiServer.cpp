//
// Created by or on 12/4/17.
//

#include "ReversiServer.h"
#include "../client/src/Cell.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_CONNECTED_CLIENTS 2

ReversiServer::ReversiServer(int port): port(port), serverSocket(0) {
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
        handleClient(clientSocket1);
        // Close communication with the client
        close(clientSocket1);
        close(clientSocket2);
    }
}
// Handle requests from a specific client
void ReversiServer::handleClient(int clientSocket) {
    int row, col;
    while (true) {
        // Read new exercise arguments
        int n = read(clientSocket, &row, sizeof(row));
        if (n == -1) {
            cout << "Error reading row" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(clientSocket, &col, sizeof(col));
        if (n == -1) {
            cout << "Error reading col" << endl;
            return;
        }
        cout << "Got Move: " << row << ", " << col <<
             endl;
        Coordinate result = getMove(row, col);
        // Write the result back to the client
        n = write(clientSocket, &result, sizeof(result));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }
}
void ReversiServer::stop() {
    close(serverSocket);
}

Coordinate ReversiServer::getMove(int row, int col) {
    Coordinate coor;
    coor.col=col;
    coor.row=row;
    return coor;
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
