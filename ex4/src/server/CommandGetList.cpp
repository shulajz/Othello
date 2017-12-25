//
// Created by shulamit on 21/12/17.
//

#include <unistd.h>
#include <iostream>
#include "CommandGetList.h"
#include "ReversiServer.h"
#include "HandleClient.h"
//
using namespace std;

CommandGetList::CommandGetList(vector<Game *> &listOfGames):Command(listOfGames) {
}

bool CommandGetList::execute(string args, ClientData* data){
    int clientSocket = data->clientSocket;
    string listOfAvailableGames;
    int buffValid;
    for(int i = 0; i < listOfGames.size(); i++) {
        if(listOfGames[i]->status == Waiting) {
            listOfAvailableGames += listOfGames[i]->name + "\n";
        }
    }
    char buff[256];
    strcpy(buff, listOfAvailableGames.c_str());
    int n = write(clientSocket, &buff, sizeof(buff));
    cout << "send the list of available games to client" << endl;
    if (n == -1) {
        cout << "Error writing to socket CommandGetList" << endl;
        return false;
    }
    buffValid = BadInput;
    n = write(clientSocket, &buffValid, sizeof(buffValid));
    cout << "send error - the name already exists in the list of games" << endl;
    if (n == -1) {
        cout << "Error writing to socket CommandStart" << endl;
        return false;
    }
    return false; //kill the thread

}