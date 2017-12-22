//
// Created by shulamit on 21/12/17.
//

#include <unistd.h>
#include <iostream>
#include "CommandGetList.h"
using namespace std;
CommandGetList::CommandGetList(vector<Game>& listOfGames, int socket):
        m_listOfGames(listOfGames), socket(socket){


}

void CommandGetList::execute(vector<string> args){
    string listOfAvailableGames;
    for(int i = 0; i < m_listOfGames.size(); i++) {
        if(m_listOfGames[i].status == Waiting) {
            listOfAvailableGames += m_listOfGames[i].name + "\n";
        }
    }
    int n = write(socket, &listOfAvailableGames, sizeof(listOfAvailableGames));
    cout << "send the list of available games to client" << endl;
    if (n == -1) {
        cout << "Error writing to socket CommandGetList" << endl;
        return;
    }

}