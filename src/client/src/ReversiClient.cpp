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
        serverIP(serverIP), serverPort(serverPort),
        clientSocket(0), canPlay(false) {
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

string ReversiClient::receiveMove() {
    // Write the exercise arguments to the socket
    string buffer="0,0" ;
    int n = read(clientSocket, &buffer, sizeof(buffer));
    if (n == -1) {
        throw "Error writing row to socket";
    }
    bool receiveMove=true;
    n = write(clientSocket, &receiveMove, sizeof(receiveMove));
    if (n == -1) {
        throw "Error writing row to socket";
    }
    cout<<"receive :"<<buffer;
    return buffer;
}

Coordinate ReversiClient::sendMove(string string) {
    // Write the exercise arguments to the socket
    int n = write(clientSocket, &string, sizeof(string));
    cout <<"flag1 " << string << endl;
    if (n == -1) {
        throw "Error writing row to socket";
    }
    Coordinate coor;
    int pos = string.find_first_of(',');
    coor.row = atoi(string.substr(pos+1).c_str());
    coor.col = atoi(string.substr(0, pos).c_str());
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
    } else if (type == '2'){
        cout<<"You play White('O')"<<endl;
        tv = White;
        return White;
    } else {
        return Empty;
    }
}

bool ReversiClient::isMyTurn(){
    int isMyTurn=0;
    int n = read(clientSocket, &isMyTurn, sizeof(isMyTurn));
    if (n == -1) {
       cout<<"isMyTurn can't read";
    }
    if (isMyTurn == 1) {
        canPlay = true;
        return true;
    }else {
        return false;
    }
}

bool ReversiClient::getIfCanPlay()const{
    return canPlay;
}

TokenValue ReversiClient::getOppositeTv()const{
    if (tv == White){
        return Black;
    } else {
        return White;
    }
}

