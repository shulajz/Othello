//
// Created by or on 12/25/17.
//

#include "GameManager.h"
GameManager::GameManager(Game game, HandleClient* server, CommandsManager* commandsManager):
        game(game), server(server), commandsManager(commandsManager) {

    data1 = new ClientData();
    data1->clientSocket = game.socket1;
    data1->server = server;
    data2 = new ClientData();
    data2->clientSocket = game.socket2;
    data2->server = server;
}

void GameManager::handleGame() {
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, gameManagerGate, (void *) this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
    cout <<"create thread for the game: "
            "the clients are: "<<data1->clientSocket<<"and "<<data2->clientSocket<<endl;
}

void *GameManager:: gameManagerGate(void* element) {
    GameManager* data = (GameManager*)element;
    data->gameManager();
}

void GameManager:: gameManager(){
    bool isContinue = true;
    while(isContinue){
        string command1;
        string args1;
        server->readCommand(game.socket1,command1,args1);
        isContinue = commandsManager->executeCommand(command1, args1,data1);
        if (!isContinue){break;}
        string command2;
        string args2;
        server->readCommand(game.socket2,command2,args2);
        isContinue = commandsManager->executeCommand(command2, args2, data2);
    }
    delete(data1);
    delete(data2);
}