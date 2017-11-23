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
    //אהבתי !:)
//המניו לא צריך להיות ניו, אל תשכחי לשים פאבליק לפני המתודות כי אז אי אפשר לגשת אליהם:)
    // לא הצלחתי להוריד את הNEW מהשחקנים באמת
    //
}