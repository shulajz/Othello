//
// Created by or on 12/4/17.
//;

#include "ReversiServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


#define MAX_CONNECTED_CLIENTS 2

ReversiServer::ReversiServer(int port): port(port),
                                        serverSocket(0),
                                        endGame(false),
                                        receiveMove(false),
                                        clientStoppedCloseAllClients(false){
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
    struct sockaddr_in clientAddress2;
    socklen_t clientAddressLen2;
    while (true) {
        clientStoppedCloseAllClients = false;
        endGame = false;
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
        while(!endGame){
            //reading from client1, writing to client2
            handleClient(clientSocket1, clientSocket2);
            if (endGame){//
                break;
            }
            //reading from client2, writing to client1
            handleClient(clientSocket2, clientSocket1);
        }
        // Close communication with the client
        cout << "close Client1" << endl;
        close(clientSocket1);
        cout << "close Client2" << endl;
        close(clientSocket2);
    }
}

void ReversiServer::handleClient(int clientSocket1, int clientSocket2) {
    int arg1 = 0;
    int arg2 = 0;
    int n = read(clientSocket1, &arg1, sizeof(arg1));
    if (n == -1) {
        cout << "Error reading row" << endl;
        return;
    }
    if(arg1 > 0 || arg1 == NoMove) {
        n = read(clientSocket1, &arg2, sizeof(arg2));
        if (n == -1) {
            cout << "Error reading col" << endl;
            return;
        } else if (arg1 == NoMove){
            cout << "Got noMove"<< endl;
        }else{
            cout << "Got Move: row: " << arg1 << " col: " << arg2 << endl;
        }
        int moveToSendToOtherClient[2];
        moveToSendToOtherClient[0] = arg1;
        moveToSendToOtherClient[1] = arg2;
        n = write(clientSocket2, &moveToSendToOtherClient, sizeof(moveToSendToOtherClient));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    } else if (arg1 == End) {
        cout << "Got End" << endl;
        endGame = true;
    } else if(arg1 == 0) {
        endGame = true;
    }
    
}

void ReversiServer::stop() {
    cout << "close server" << endl;
    close(serverSocket);
}

void ReversiServer::sendValueOfClient(int clientSocket1, int clientSocket2) {
    char player1 = '1';
    char player2 = '2';
    int n = write(clientSocket1, &player1, sizeof(player1));
    cout << "Write on ClientSocket1 he play Black ('x')" << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
    n = write(clientSocket2, &player2, sizeof(player2));
    cout << "Write on ClientSocket2 he play White ('o') " << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}
