//
// Created by shulamit on 21/12/17.
////

#include "CommandClose.h"
#include "HandleClient.h"

using namespace std;

CommandClose::CommandClose(vector<Game *> &listOfGames):Command(listOfGames) {
}
bool CommandClose::execute(string args,ClientData* data){
    int clientSocket = data->clientSocket;
    for(int i = 0; i < listOfGames.size(); i++) {
        if(listOfGames[i]->socket1 == clientSocket ||
                listOfGames[i]->socket2 == clientSocket) {
            cout << "close Client "<< listOfGames[i]->socket1<< endl;
            close(listOfGames[i]->socket2);
            cout << "close Client " <<listOfGames[i]->socket2 << endl;
            close(listOfGames[i]->socket1);
            cout<<"close the game :" << listOfGames[i]->name << endl;
            delete(listOfGames[i]); //delete game
            listOfGames.erase(listOfGames.begin()+i); //remove the game from the list
            break;
        }
    }
    return false;
}
//