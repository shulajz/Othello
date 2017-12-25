//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REVERSICLIENT_H
#define OTHELLO_REVERSICLIENT_H

#include "Menu.h"
#include <string.h>
#include <iostream>
using namespace std;



class ReversiClient {
public:
    ReversiClient(const char *serverIP, int serverPort);
    void connectToServer();
    /**
     * send a coordinate to the other player
     * @param coordinate 
     */
    void sendMove(Coordinate input);
    /**
     * receive a coordinate from the other player
     * @return 
     */
    Coordinate receiveMove();
    TokenValue getTokenValueOfPlayer();
    int getValid();
    void sendEnd();
    void sendNoMove();
    void sendCommand(string command,  Menu* subMenu);
    void printList( Menu* subMenu);
    ~ReversiClient();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    TokenValue tv;

};


#endif //OTHELLO_REVERSICLIENT_H