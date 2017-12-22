//
// Created by shulamit on 21/12/17.
//

#include "CommandClose.h"

#include <unistd.h>
#include <iostream>
using namespace std;

CommandClose::CommandClose(vector<Game>& listOfGames, int socket):
        m_listOfGames(listOfGames), socket(socket){
}

void CommandClose::execute(vector<string> args){
    string listOfAvailableGames;
    for(int i = 0; i < m_listOfGames.size(); i++) {
        if(m_listOfGames[i].name == args[0]) {
            cout << "close Client1" << endl;
            close(m_listOfGames[i].socket1);
            cout << "close Client2" << endl;
            close(m_listOfGames[i].socket2);
            break;
        }
    }
}