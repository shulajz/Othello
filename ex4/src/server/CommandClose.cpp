//
// Created by shulamit on 21/12/17.
////

#include "CommandClose.h"
#include "HandleClient.h"
#include <unistd.h>
#include <iostream>

using namespace std;

CommandClose::CommandClose(vector<Game *> &listOfGames):Command(listOfGames) {
}
bool CommandClose::execute(string args,ClientData* data){
    //    string listOfAvailableGames;
    int clientSocket = data->clientSocket;
    char buffClose[6] = "close";
    for(int i = 0; i < listOfGames.size(); i++) {
        if(listOfGames[i]->socket1 == clientSocket ||
                listOfGames[i]->socket2 == clientSocket) {
            cout << "close Client "<< listOfGames[i]->socket1<< endl;
            close(listOfGames[i]->socket2);
            cout << "close Client " <<listOfGames[i]->socket2 << endl;
            close(listOfGames[i]->socket1);
            listOfGames.erase(listOfGames.begin()+i);
            break;
        }
    }
    return false;
}