//
// Created by or on 12/4/17.
//

#include "ReversiClient.h"
//#include "../../server/ReversiServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sstream>


ReversiClient::ReversiClient(const char *serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort), clientSocket(0),tv(Empty) {
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
}
ReversiClient::~ReversiClient() {
    close(clientSocket);
}
Coordinate ReversiClient::receiveMove() {
    // read the Move from the socket
    int moveReceivedFromOtherPlayer[2];
    
    int n = read(clientSocket, moveReceivedFromOtherPlayer, sizeof(moveReceivedFromOtherPlayer));
    if (n == -1) {
        throw "Error reading move from the socket";
    }
    Coordinate moveReceived;
    moveReceived.row = moveReceivedFromOtherPlayer[0];
    moveReceived.col = moveReceivedFromOtherPlayer[1];
    cout<<"row: "<<moveReceivedFromOtherPlayer[0] 
        << endl << "col: "<< moveReceivedFromOtherPlayer[1]<<endl;
    return moveReceived;
}

void ReversiClient::sendMove(Coordinate input) {
    // Write the move to the socket
    cout<<"row sendMove: "<<input.row
        << endl << "col sendMove: "<<input.col<<endl;
    stringstream stream1;
    stream1 << input.row << " " << input.col;
    string inputCoordinateString = stream1.str();

    string playCoordinate = "play ";
    playCoordinate += inputCoordinateString;
    char buff[50];
    strcpy(buff, playCoordinate.c_str());
    cout<<"the buffer is: " << buff << endl;
    int n = write(clientSocket, &buff, sizeof(buff));
    if (n == -1) {
        throw "Error writing row to socket";
    }

}

void ReversiClient::sendNoMove() {
    // Write the NoMove to the socket
    int noMove = NoMove;
    int n = write(clientSocket, &noMove, sizeof(noMove));
    if (n == -1) {

        throw "Error writing row to socket";
    }
    n = write(clientSocket, &noMove, sizeof(noMove));
    if (n == -1) {
        throw "Error writing row to socket";
    }
}

void ReversiClient::sendEnd() {
    // Write End to the socket
    int end = End;
    char closeStr[6] = "close";
    int n = write(clientSocket, &closeStr, sizeof(closeStr));
    if (n == -1) {
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

void ReversiClient :: sendCommand(string command, Menu* subMenu) {
    char buffer[50];
    strcpy(buffer, command.c_str());
    int n = write(clientSocket, &buffer, sizeof(buffer));
    if (n == -1) {
        throw "Error writing row to socket in send command";
    }
    if(command == "list_games") {
        printList(subMenu);
    }
}

void ReversiClient :: printList(Menu* subMenu) {
    char listOfAvailableGames[256];
    int n = read(clientSocket, &listOfAvailableGames, sizeof(listOfAvailableGames));
    if (n == -1) {
        throw "Error reading move from the socket in print list method";
    }
    string buff(listOfAvailableGames);
    subMenu->printList(buff);
}

int ReversiClient::getValid() {
    int buff;
    int n = read(clientSocket, &buff, sizeof(buff));
    if (n == -1) {
        throw "Error reading getValid";
    }
    return buff;
}