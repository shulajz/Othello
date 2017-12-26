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
    cout <<"create game with the name : "<<game.name<<
            " and the clients are: client"<<data1->clientSocket<<" and client"<<data2->clientSocket<<endl;
    sendValueOfClient(data1->clientSocket, data2->clientSocket);
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
    cout<<"close the game :" << game.name << endl;
    delete(data1);
    delete(data2);
}

void GameManager::sendValueOfClient(int clientSocket1, int clientSocket2) {
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