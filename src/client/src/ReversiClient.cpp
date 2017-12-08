//
// Created by or on 12/4/17.
//

#include "ReversiClient.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstdlib>
#include <unistd.h>


ReversiClient::ReversiClient(const char *serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort), clientSocket(0),tv(Empty) {
}

void ReversiClient::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cout<<"here1";
        throw "Error opening socket";
    }
    /// Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        cout<<"here2";
        throw "Can't parse IP address";
    }
    /// Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        cout<<"here3";
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
        cout<<"here4";
        throw "Error connecting to server";
    }
    cout <<"Waiting for other player to join..." << endl;
}

Coordinate ReversiClient::receiveMove() {
    // Write the Move to the socket
    int moveReceivedFromOtherPlayer[2];

    int n = read(clientSocket, &moveReceivedFromOtherPlayer, sizeof(moveReceivedFromOtherPlayer));
    if (n == -1) {
        cout<<"here5";
        throw "Error reading move from the socket";
    }

    Coordinate moveReceived;
    moveReceived.row = moveReceivedFromOtherPlayer[0];
    moveReceived.col = moveReceivedFromOtherPlayer[1];
    return moveReceived;
}

void ReversiClient::sendMove(Coordinate coordinate) {
    // Write the move to the socket
    int row = coordinate.row;
    int col = coordinate.col;
    int n = write(clientSocket, &row, sizeof(row));
    if (n == -1) {
        cout<<"here6";
        throw "Error writing row to socket";
    }
    n = write(clientSocket, &col, sizeof(col));
    if (n == -1) {
        cout<<"here7";
        throw "Error writing row to socket";
    }

}

//void ReversiClient::sendNoMove() {
//    // Write the move to the socket
////    string noMove = "no move for the player";
//    int noMove = NoMove;
//
//    int n = write(clientSocket, &noMove, sizeof(noMove));
//    if (n == -1) {
//        throw "Error writing row to socket";
//    }
//}

void ReversiClient::sendEnd() {
    // Write the move to the socket
    int end = End;
    int n = write(clientSocket, &end, sizeof(end));
    if (n == -1) {
        cout<<"here8";
        throw "Error writing row to socket";
    }
}

TokenValue ReversiClient::getTokenValueOfPlayer(){
    char type;
    int n = read(clientSocket, &type, sizeof(type));
    if (n == -1) {
        return Empty;
    }
    if (type == '1'){
        tv = Black;
        return Black;
    } else if (type == '2'){
        tv = White;
        return White;
    } else {
        return Empty;
    }
}