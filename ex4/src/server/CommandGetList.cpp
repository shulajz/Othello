//
// Created by shulamit on 21/12/17.
//

#include <unistd.h>
#include <iostream>
#include "CommandGetList.h"
#include "HandleClient.h"
#include "ReversiServer.h"
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
    //send the list of available games to client
    char buff[256];
    strcpy(buff, listOfAvailableGames.c_str());
    int n = write(clientSocket, &buff, sizeof(buff));
    cout << "send the list of available games to client "<< clientSocket << endl;
    if (n == -1) {
        cout << "Error writing to socket CommandGetList" << endl;
        return false;
    }
    //send badInput to the client that will
    // know that he need to choose another selection
    buffValid = BadInput;
    n = write(clientSocket, &buffValid, sizeof(buffValid));
    if (n == -1) {
        cout << "Error writing to socket CommandStart" << endl;
        return false;
    }
    close(data->clientSocket);
    return false; //kill the thread
}