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
    char buffClose[6] = "close";
    for(int i = 0; i < listOfGames.size(); i++) {
        if(listOfGames[i]->socket1 == clientSocket ||
                listOfGames[i]->socket2 == clientSocket) {
            cout << "close Client "<< listOfGames[i]->socket1<< endl;
            close(listOfGames[i]->socket2);
            cout << "close Client " <<listOfGames[i]->socket2 << endl;
            close(listOfGames[i]->socket1);
            delete(listOfGames[i]); //delete the game
            listOfGames.erase(listOfGames.begin()+i); //remove this game from the listOfGames
            break;
        }
    }
    return false;
}