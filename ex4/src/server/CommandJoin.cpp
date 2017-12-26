//
// Created by shulamit on 21/12/17.
////
#include <iostream>
#include <unistd.h>
#include "CommandsManager.h"
#include "CommandJoin.h"
#include "ReversiServer.h"
#include "HandleClient.h"
#include "HandleClient.h"
#include "GameManager.h"

CommandJoin::CommandJoin(vector<Game *> &listOfGames, CommandsManager* commandsManager):
        commandsManager(commandsManager), Command(listOfGames)  {
}

bool CommandJoin::execute(string args, ClientData* data){
    int clientSocket = data->clientSocket;
    int buffValid;
    Game currGame;

    for(int i = 0; i < listOfGames.size(); i++) {
        // in case tha args-the name of game that the user want to join is exist in the list
        //and in status waiting create game and send it to the game manager
        //if so send goodInput to the client
        if (args == listOfGames[i]->name && listOfGames[i]->status == Waiting) {
            cout << "client"<<clientSocket<<" join"<<endl;
            listOfGames[i]->socket2 = clientSocket;
            listOfGames[i]->status = Active;
            buffValid = GoodInput;
            int n = write(listOfGames[i]->socket2, &buffValid,
                          sizeof(buffValid));
            if (n == -1) {
                cout << "Error writing to socket command join" << endl;
                return false;
            }
            sendValueOfClient(listOfGames[i]->socket1, listOfGames[i]->socket2);
            currGame = *listOfGames[i];
            GameManager gameManager(currGame, data->server, commandsManager);
            gameManager.handleGame();
            return false;//kill the thread
        }
    }
    //there's no such game is waiting to join of other client, write to client that its invalid
    //if so send badInput to the client
    buffValid = BadInput;
    int n = write(clientSocket, &buffValid,
                  sizeof(buffValid));
    if (n == -1) {
        cout << "Error writing to socket command join2" << endl;
        return false;
    }

    return false; //kill the thread
}


void CommandJoin::sendValueOfClient(int clientSocket1, int clientSocket2) {
    char player1 = '1';
    char player2 = '2';
    int n = write(clientSocket1, &player1, sizeof(player1));
    cout << "Write on ClientSocket "<< clientSocket1<<" he play Black ('x')" << endl;
    if (n == -1) {
        cout << "Error writing to socket command sendValueOfClient1" << endl;
        return;
    }
    n = write(clientSocket2, &player2, sizeof(player2));
    cout << "Write on ClientSocket "<< clientSocket2<<" he play White ('o') " << endl;
    if (n == -1) {
        cout << "Error writing to socket command sendValueOfClient2" << endl;
        return;
    }
}