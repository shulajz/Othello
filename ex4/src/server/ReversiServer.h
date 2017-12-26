//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REVERSISERVER_H
#define OTHELLO_REVERSISERVER_H
#include <string.h>
#include <iostream>
#include "vector"
#include "CommandsManager.h"


using namespace std;

enum correctInput {
    GoodInput, BadInput,
};

class ReversiServer {
public:
    ReversiServer(int port);
    void start();
    void stop();

private:
    int port;
    int serverSocket; // the socket's file descriptor;

    /**
     * send the value of the client in the start of the game
     * @param clientSocket1
     * @param clientSocket2
     */

};




#endif //OTHELLO_REVERSISERVER_H