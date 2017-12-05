//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REVERSICLIENT_H
#define OTHELLO_REVERSICLIENT_H


#include "Cell.h"

class ReversiClient {
public:
    ReversiClient(const char *serverIP, int serverPort);
    void connectToServer();
    Coordinate sendMove(int row, int col);
    TokenValue getTokenValueOfPlayer();
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;

};


#endif //OTHELLO_REVERSICLIENT_H