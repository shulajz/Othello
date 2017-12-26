//
// Created by or on 12/25/17.
//

#ifndef OTHELLO_GAMEMANAGER_H
#define OTHELLO_GAMEMANAGER_H


#include "Command.h"
#include "HandleClient.h"

class GameManager {
public:
    GameManager(Game game,HandleClient* server, CommandsManager* commandsManager);
    void handleGame();
    static void * gameManagerGate(void* element);
    void  gameManager();
   // ~GameManager();
private:
    Game game;
    HandleClient* server;
    ClientData* data1;
    ClientData* data2;
    CommandsManager* commandsManager;


};


#endif //OTHELLO_GAMEMANAGER_H
