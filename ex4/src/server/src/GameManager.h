//
// Created by or on 12/25/17.
//

#ifndef OTHELLO_GAMEMANAGER_H
#define OTHELLO_GAMEMANAGER_H
//

#include "Command.h"
#include "HandleClientReversi.h"

class GameManager {
public:
    GameManager(Game game,HandleClientReversi* server,
                CommandsManager* commandsManager);
    void handleGame();
    static void * gameManagerGate(void* element);
    /**
    * send the value of the client in the start of the game
    * @param clientSocket1
    * @param clientSocket2
    */
    void sendValueOfClient(int clientSocket1, int clientSocket2);
    /**
     * handles the game
     */
    void  gameManager();
private:
    Game game;
    HandleClientReversi* handleClientReversi;
    ClientData* data1;
    ClientData* data2;
    CommandsManager* commandsManager;
    pthread_t thread;
};



#endif //OTHELLO_GAMEMANAGER_H
