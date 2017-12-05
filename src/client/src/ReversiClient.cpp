//
// Created by or on 12/4/17.
//

#include "ReversiClient.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;
ReversiClient::ReversiClient(const char *serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort),
        clientSocket(0) {
}

void ReversiClient::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    /// Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    /// Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char
    *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }

    cout <<"Waiting for other player to join..." << endl;
}

Coordinate ReversiClient::receiveMove() {
    // Write the exercise arguments to the socket
    Coordinate coordinate;
    int n = read(clientSocket, &coordinate, sizeof(coordinate));
    if (n == -1) {
        throw "Error writing row to socket";
    }
    return coordinate;
}


Coordinate ReversiClient::sendMove(int row,int col) {
    // Write the exercise arguments to the socket
    int n = write(clientSocket, &row, sizeof(row));
    cout <<"flag1 " << row << endl;
    if (n == -1) {
        throw "Error writing row to socket";
    }
    n = write(clientSocket, &col, sizeof(col));
    cout << "flag2 " <<col << endl;

    if (n == -1) {
        throw "Error writing col to socket";
    }
    // Read the result from the server
    Coordinate coor;
    n = read(clientSocket, &coor, sizeof(coor));
    if (n == -1) {
        throw "Error reading result from socket";
    }
 //   int row1,col1;

//    n = read(clientSocket, &row1, sizeof(row1));
//    cout << "flag3 " << row1 << endl;
//
//    if (n == -1) {
//        throw "Error writing row to socket";
//    }
//    n = read(clientSocket, &col1, sizeof(col1));
//    cout << "flag4 " << col1 << endl;
//
//    if (n == -1) {
//        throw "Error writing col to socket";
//    }

    cout<<"row:"<<coor.row<<endl<<"col:"<<coor.col<<endl;
    return coor;
}

TokenValue ReversiClient::getTokenValueOfPlayer(){
    char type;
    int n = read(clientSocket, &type, sizeof(type));
    if (n == -1) {
        return Empty;
    }
    if (type == '1'){
        cout<<"You play Black('X')"<<endl;
        tv = Black;
        return Black;
    }else if(type == '2'){
        cout<<"You play White('O')"<<endl;
        tv = White;
        return White;
    }else{
        return Empty;
    }
}
bool ReversiClient::isMyTurn(){
    int isMyTurn=2;
    int n = read(clientSocket, &isMyTurn, sizeof(isMyTurn));
    if (n == -1) {
       cout<<"isMyTurn can't read";
    }
    bool wroteAlready = false;
    while(isMyTurn == 0){
        if(!wroteAlready) {
            cout<< "waiting for opponents turn (:" << endl;
            wroteAlready = true;
        }

    }
}

TokenValue ReversiClient::getOppositeTv()const{
    if (tv == White){
        return Black;
    } else {
        return White;
    }
}

