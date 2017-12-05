//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REVERSISERVER_H
#define OTHELLO_REVERSISERVER_H


#include "../client/src/Cell.h"

class ReversiServer {
public:
    ReversiServer(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int clientSocket1, int clientSocket2);
    Coordinate getMove(int row, int col);
    void sendValueOfClient(int clientSocket1, int clientSocket2);
    void sendWhoNeedToPlay(int clientSocket1, int clientSocket2);

};


#endif //OTHELLO_REVERSISERVER_H