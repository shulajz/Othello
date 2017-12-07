/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/

#include "Tools.h"

#include "Board.h"
#include "GameFlow.h"
#include "RealPlayer.h"
#include "ClassicRules.h"
#include "ConsoleTokenFactory.h"
#include "ConsoleBoard.h"
#include "Menu.h"
#include "ConsoleMenu.h"
#include "RemotePlayer.h"

int main() {

    ConsoleBoard consoleBoard(DIM);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;
    ConsoleMenu consoleMenu;
    Board board (DIM, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(DIM));
    //RealPlayer realPlayer(Black);
    consoleMenu.printOptionsMenu();
    Player* p2 = consoleMenu.choosePlayer();
    Player* players[2];
    Player* p1;
    Player *remotePlayer;
    if(p2 == NULL){
        remotePlayer = new RemotePlayer(Black);
        if(remotePlayer->getValue() == Black) {
            //if this is the first client
            p1 = new RealPlayer(Black);
            p2 = remotePlayer;
            remotePlayer->setTokenValue(White);
        } else {
            //this is the second client
            p1 = remotePlayer;
            remotePlayer->setTokenValue(Black);
            p2 = new RealPlayer(White);
        }
//        p2=new DemoPlayer(White,p1->getClient());
    }else{
        p1 = new RealPlayer (Black);
    }


    players[Black] = p1;
    players[White] = p2;
    GameFlow gameFlow(classicRules, players, board, consoleBoard);
    gameFlow.run();
    delete(players[1]);
}