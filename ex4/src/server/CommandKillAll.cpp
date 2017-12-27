//
// Created by or on 12/26/17.
//

#include <unistd.h>
#include "CommandKillAll.h"

CommandKillAll::CommandKillAll(vector <Game*> &listOfGames): Command(listOfGames){
}

bool CommandKillAll::execute(string args, ClientData* data){
    int closeClients[2];
    closeClients[0] = Close;
    closeClients[1] = Close;
    for (int i = 0; i < listOfGames.size(); i++) {
        int n = write(listOfGames[i]->socket1, &closeClients, sizeof(closeClients));
        if (n == -1) {
            throw "Error reading move from the socket";
        }
        close(listOfGames[i]->socket1);
        if(listOfGames[i]->socket2 != 0) {
            int n = write(listOfGames[i]->socket2, &closeClients, sizeof(closeClients));
            if (n == -1) {
                throw "Error reading move from the socket";
            }
            close(listOfGames[i]->socket2);
        }
    }
}