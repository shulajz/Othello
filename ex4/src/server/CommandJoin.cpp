//
// Created by shulamit on 21/12/17.
//
#include <iostream>
#include <unistd.h>
#include "CommandsManager.h"
#include "CommandJoin.h"
#include "ReversiServer.h"
#include "HandleClient.h"


CommandJoin::CommandJoin(vector<Game *> &listOfGames):Command(listOfGames)  {
}

bool CommandJoin::execute(string args, ClientData* data){
    int clientSocket = data->clientSocket;
    int buffValid;
    for(int i = 0; i < listOfGames.size(); i++) {
        if (args == listOfGames[i]->name) {
            listOfGames[i]->socket2 = clientSocket;
            listOfGames[i]->status = Active;
            buffValid = GoodInput;
            int n = write(listOfGames[i]->socket2, &buffValid,
                          sizeof(buffValid));
            if (n == -1) {
                cout << "Error writing to socket command join" << endl;
                return false;
            }
            sendValueOfClient(listOfGames[i]->socket1, listOfGames[i]->socket2);
            return true;//dont kill the thread
        }
    }
    //there's no such game, write to client that its invalid
    buffValid = BadInput;
    int n = write(clientSocket, &buffValid,
                  sizeof(buffValid));
    if (n == -1) {
        cout << "Error writing to socket command join2" << endl;
        return false;
    }
    return true; //dont kill the thread
}


void CommandJoin::sendValueOfClient(int clientSocket1, int clientSocket2) {
    char player1 = '1';
    char player2 = '2';
    int n = write(clientSocket1, &player1, sizeof(player1));
    cout << "Write on ClientSocket1 he play Black ('x')" << endl;
    if (n == -1) {
        cout << "Error writing to socket command sendValueOfClient1" << endl;
        return;
    }
    n = write(clientSocket2, &player2, sizeof(player2));
    cout << "Write on ClientSocket2 he play White ('o') " << endl;
    if (n == -1) {
        cout << "Error writing to socket command sendValueOfClient2" << endl;
        return;
    }
}