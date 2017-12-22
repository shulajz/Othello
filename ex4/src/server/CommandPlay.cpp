//
// Created by shulamit on 21/12/17.
//

#include "CommandPlay.h"
#include <unistd.h>
#include <iostream>
#include <cstdlib>

using namespace std;

CommandPlay::CommandPlay(vector<Game>& listOfGames, int socket):
        m_listOfGames(listOfGames), socket(socket){
}

void CommandPlay::execute(vector<string> args){

    int moveToSendToOtherClient[2];
    moveToSendToOtherClient[0] = atoi(args[0]);
    moveToSendToOtherClient[1] = atoi(args[1]);
    string listOfAvailableGames;
    for(int i = 0; i < m_listOfGames.size(); i++) {
        if(socket == m_listOfGames[i].socket1) {
            int n = write(m_listOfGames[i].socket2, &moveToSendToOtherClient,
                          sizeof(moveToSendToOtherClient));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                return;
            }
            return;
        } else if(socket == m_listOfGames[i].socket2) {
            int n = write(m_listOfGames[i].socket1, &moveToSendToOtherClient,
                          sizeof(moveToSendToOtherClient));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                return;
            }
            return;
        }
    }
}