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
    Coordinate receiveMove();

    TokenValue getTokenValueOfPlayer();
    TokenValue getOppositeTv()const;
    bool isMyTurn();
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    TokenValue tv;

};


#endif //OTHELLO_REVERSICLIENT_H