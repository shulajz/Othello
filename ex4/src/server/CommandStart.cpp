//
// Created by shulamit on 21/12/17.
//

#include <unistd.h>
#include <iostream>
#include "CommandStart.h"

CommandStart::CommandStart(vector<Game>& listOfGames, int socket):
        m_listOfGames(listOfGames), socket(socket){


}

void CommandStart::execute(vector<string> args){
    int error = -1;
    for(int i = 0; i < m_listOfGames.size(); i++) {
        if (args[0] == m_listOfGames[i].name) {
            int n = write(socket, &error, sizeof(error));
            cout << "send error - the name already exists in the list of games" << endl;
            if (n == -1) {
                cout << "Error writing to socket CommandStart" << endl;
                return;
            }
            return; //return from the method, the name is not available
        }
    }

    Game game;
    game.name = args[0];
    game.socket1 = socket;
    game.socket2 = 0;
    game.status = Waiting;
    m_listOfGames.push_back(game);
}