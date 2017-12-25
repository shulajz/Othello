//
// Created by shulamit on 21/12/17.
//

#include "CommandPlay.h"
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "ReversiServer.h"
#include "HandleClient.h"

using namespace std;

CommandPlay::CommandPlay(vector<Game *> &listOfGames):Command(listOfGames)  {
}

bool CommandPlay::execute(string args, ClientData* data){
    cout << "args in commandPlay:" << args<< endl;
    int clientSocket = data->clientSocket;
    int row, col;
    parseArgsToRowAndCol(args,row, col);
    int moveToSendToOtherClient[2];
    moveToSendToOtherClient[0] = row;
    moveToSendToOtherClient[1] = col;
    cout<<"row: "<<moveToSendToOtherClient[0]
        << endl << "col: "<< moveToSendToOtherClient[1]<<endl;
    for(int i = 0; i < listOfGames.size(); i++) {
        if(clientSocket == listOfGames[i]->socket1) {
            int n = write(listOfGames[i]->socket2, &moveToSendToOtherClient,
                          sizeof(moveToSendToOtherClient));
            if (n == -1) {
                cout << "Error writing to socket command play1" << endl;
                return false;
            }
            return true; // don't kill the thread
        } else if(clientSocket == listOfGames[i]->socket2) {
            int n = write(listOfGames[i]->socket1, &moveToSendToOtherClient,
                          sizeof(moveToSendToOtherClient));
            if (n == -1) {
                cout << "Error writing to socket command play1" << endl;
                return false;
            }
            return true;// dont kill the tread
        }
    }
}

void CommandPlay::parseArgsToRowAndCol(string args, int& row, int& col){
    string buf; // Have a buffer string
    stringstream ss(args); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    row = atoi(tokens[0].c_str());
    col = atoi(tokens[1].c_str());
    cout<<"command row: "<<row
        << endl << "command col: "<< col<<endl;
}