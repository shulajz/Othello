//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REVERSICLIENT_H
#define OTHELLO_REVERSICLIENT_H

#include "Cell.h"
#include <string.h>
#include <iostream>
using namespace std;



class ReversiClient {
public:
    ReversiClient(const char *serverIP, int serverPort);
    void connectToServer();
    void sendMove(Coordinate coordinate);
    Coordinate receiveMove();
    TokenValue getTokenValueOfPlayer();
    void sendEnd();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    TokenValue tv;

};


#endif //OTHELLO_REVERSICLIENT_H