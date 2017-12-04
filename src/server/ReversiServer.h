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
    void handleClient(int clientSocket);
    Coordinate getMove(int row, int col) ;

};


#endif //OTHELLO_REVERSISERVER_H
