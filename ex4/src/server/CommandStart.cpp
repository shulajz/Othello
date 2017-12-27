//
// Created by shulamit on 21/12/17.
///

#include <unistd.h>
#include <iostream>
#include "CommandStart.h"
#include "HandleClient.h"
#include "ReversiServer.h"


CommandStart::CommandStart(vector<Game *> &listOfGames):Command(listOfGames)  {
}



bool CommandStart::execute(string args, ClientData* data){
    int buffValid;
    int clientSocket = data->clientSocket;
    //checking if the name already exists and waiting to other client to join,
    //if so send badInput to the client
    for(int i = 0; i < listOfGames.size(); i++) {
        if (args == listOfGames[i]->name && listOfGames[i]->status == Waiting) {
            buffValid = BadInput;
            int n = write(clientSocket, &buffValid, sizeof(buffValid));
            cout << "send error - the name already exists in the list of games" << endl;
            if (n == -1) {
                cout << "Error writing to socket CommandStart" << endl;
                return false;
            }
            cout << "close Client" << clientSocket << endl;
            close(clientSocket);
            return true; //dont kill the thread! cause the user got it wrong
        }
    }
    //if the name of the game available then send GoodInput to the client
    // and create the struct of the game.
    buffValid = GoodInput;
    int n = write(clientSocket, &buffValid, sizeof(buffValid));
    if (n == -1) {
        cout << "Error writing to socket CommandStart" << endl;
        return false;
    }
    Game* game = new Game() ;
    game->name = args;
    game->socket1 =clientSocket;
    game->socket2 = 0;
    game->status = Waiting;
    ///lock ?
    listOfGames.push_back(game);
    return false; //kill the thread cause we create after a new game
}