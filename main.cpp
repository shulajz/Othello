//
// Created by shulamit on 11/1/17.
//


#include "Board.h"
#include "GameFlow.h"
#include "RealPlayer.h"
#include "ClassicRules.h"
#include "ConsoleTokenFactory.h"
#include "ConsoleBoard.h"
#include "AIPlayer.h"
#include "Menu.h"
#include "ConsoleMenu.h"


#define DIM 9
//using namespace std;

int main() {

    ConsoleBoard consoleBoard(DIM);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;
    Menu* menu =new ConsoleMenu();
    Board board (DIM, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(DIM));
    RealPlayer p1(Black);
    menu->printOptionsMenu();
    Player* p2=menu->choosePlayer();
    Player* players[2];
    players[Black] = &p1;
    players[White] = p2;
    GameFlow gameFlow(classicRules, players, board, consoleBoard);
    gameFlow.run();
    delete(players[1]);
    delete(menu);

}
