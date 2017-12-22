//
// Created by shulamit on 21/12/17.
//
#include <iostream>
#include <unistd.h>
#include "CommandsManager.h"
#include "CommandJoin.h"

CommandJoin::CommandJoin(vector<Game>& listOfGames, int socket):
        m_listOfGames(listOfGames), socket(socket){

}

void CommandJoin::execute(vector<string> args){

    for(int i = 0; i < m_listOfGames.size(); i++) {
        if(args[0] == m_listOfGames[i].name) {
            m_listOfGames[i].socket2 = socket;
            sendValueOfClient(m_listOfGames[i].socket1, m_listOfGames[i].socket2);
            m_listOfGames[i].status = Active;
            break;
        }

    /// need to write to the socket if failed
}

void CommandJoin::sendValueOfClient(int clientSocket1, int clientSocket2) {
    char player1 = '1';
    char player2 = '2';
    int n = write(clientSocket1, &player1, sizeof(player1));
    cout << "Write on client 1 join" << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
    n = write(clientSocket2, &player2, sizeof(player2));
    cout << "Write on client 2 join" << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}