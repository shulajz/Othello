//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REVERSISERVER_H
#define OTHELLO_REVERSISERVER_H
#include <string.h>
#include <iostream>


using namespace std;

enum StatusOfClientInGame {
    Active, Waiting
};

struct Game{
    string name;
    int socket1;
    int socket2;
    StatusOfClientInGame status;
};

enum StatusForClient {
    NoMove = -2, End = -3
};

class ReversiServer {
public:
    ReversiServer(int port);
    void start();
    void stop();
private:
    bool receiveMove;
    bool endGame;
    int port;
    int serverSocket; // the socket's file descriptor;
    void handleClient(int clientSocket1, int clientSocket2);
    /**
     * send the value of the client in the start of the game
     * @param clientSocket1
     * @param clientSocket2
     */
    void sendValueOfClient(int clientSocket1, int clientSocket2);
    bool clientStoppedCloseAllClients;
};


#endif //OTHELLO_REVERSISERVER_H