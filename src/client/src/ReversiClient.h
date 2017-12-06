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
    Coordinate sendMove(int row, int col);
    Coordinate sendMove(string string);
    string receiveMove();
    bool getIfClientCanReceiveMove();
    TokenValue getTokenValueOfPlayer();
    TokenValue getOppositeTv()const;
    bool isMyTurn();
    bool getIfCanPlay()const;
private:
    bool canPlay;
    const char *serverIP;
    int serverPort;
    int clientSocket;
    TokenValue tv;

};


#endif //OTHELLO_REVERSICLIENT_H