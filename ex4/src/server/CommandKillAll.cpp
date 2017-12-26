//
// Created by or on 12/26/17.
//

#include <unistd.h>
#include <iostream>
#include "CommandKillAll.h"

CommandKillAll::CommandKillAll(vector <Game*> &listOfGames): Command(listOfGames){
}

bool CommandKillAll::execute(string args, ClientData* data){
    for (int i = 0; i < listOfGames.size(); i++) {
        close(listOfGames[i]->socket1);
        cout << "close client" << listOfGames[i]->socket1 << endl;
        if(listOfGames[i]->socket2 > 0) {
            close(listOfGames[i]->socket2);
            cout << "close client" << listOfGames[i]->socket2 << endl;
        }
    }
    return false;
}