/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/

#include <sstream>
#include <cstdlib>
#include "Tools.h"
#include "Board.h"
#include "RealPlayer.h"
#include "ClassicRules.h"
#include "ConsoleTokenFactory.h"
#include "ConsoleBoard.h"
#include "Menu.h"
#include "ConsoleMenu.h"
#include "GameFlow.h"

int main() {
    ConsoleBoard consoleBoard(DIM);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;
    ConsoleMenu consoleMenu;
    Board board (DIM, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(DIM));
    Player* players[2];
    consoleMenu.getChoose(players);
    GameFlow gameFlow(classicRules, players, board, consoleBoard);
    gameFlow.run();
    delete(players[0]);
    delete(players[1]);

}