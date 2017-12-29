//
// Created by or on 12/25/17.
//
//
#include "GameManager.h"
#include <pthread.h>

GameManager::GameManager(Game game, HandleClient* handleClient, CommandsManager* commandsManager):
        game(game), handleClient(handleClient), commandsManager(commandsManager) {

    data1 = new ClientData();
    data1->clientSocket = game.socket1;
    data1->handleClient = handleClient;
    data2 = new ClientData();
    data2->clientSocket = game.socket2;
    data2->handleClient = handleClient;
}

void GameManager::handleGame() {
    //create thread for the game
    int rc = pthread_create(&thread, NULL, gameManagerGate, (void *) this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
    handleClient->pushThread(thread);
    cout <<"create game with the name : "<<game.name<<
            " ,the clients are: client"<<data1->clientSocket<<" and client"<<data2->clientSocket<<endl;
}

void *GameManager:: gameManagerGate(void* element) {
    GameManager* data = (GameManager*)element;
    data->gameManager();
}


void GameManager:: gameManager(){
    sendValueOfClient(data1->clientSocket, data2->clientSocket);
    bool isContinue = true;
    //the game will continue until get a command of close
    // from any client.
    while(isContinue){
        string command1;
        string args1;
        handleClient->readCommand(game.socket1,command1,args1);
        isContinue = commandsManager->executeCommand(command1, args1, data1);
        if (!isContinue){break;}
        string command2;
        string args2;
        handleClient->readCommand(game.socket2,command2,args2);
        isContinue = commandsManager->executeCommand(command2, args2, data2);
    }
    cout<<"close the game :" << game.name << endl;
    delete(data1);
    delete(data2);
    handleClient->eraseThread(thread);
}

void GameManager::sendValueOfClient(int clientSocket1, int clientSocket2) {
    char player1 = '1';
    char player2 = '2';
    int n = write(clientSocket1, &player1, sizeof(player1));
    cout << "send to Client "<< clientSocket1<<" he play Black ('x')" << endl;
    if (n == -1) {
        cout << "Error writing to socket command sendValueOfClient1" << endl;
        return;
    }
    n = write(clientSocket2, &player2, sizeof(player2));
    cout << "send to Client "<< clientSocket2<<" he play White ('o') " << endl;
    if (n == -1) {
        cout << "Error writing to socket command sendValueOfClient2" << endl;
        return;
    }
}