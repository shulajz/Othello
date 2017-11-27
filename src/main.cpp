/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:313485690
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

int main() {

    ConsoleBoard consoleBoard(DIM);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;
    ConsoleMenu consoleMenu;
    Board board (DIM, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(DIM));
    RealPlayer realPlayer(Black);
    consoleMenu.printOptionsMenu();
    Player* p2 = consoleMenu.choosePlayer();
    Player* players[2];
    players[Black] = &realPlayer;
    players[White] = p2;
    GameFlow gameFlow(classicRules, players, board, consoleBoard);
    gameFlow.run();
    delete(players[1]);
}