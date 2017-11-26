//
// Created by shulamit on 10/31/17.
//

#include "RealPlayer.h"
#include <iostream>
#include <list>
#include <limits>

using namespace std;

RealPlayer :: RealPlayer(TokenValue tv) {
    this->tv = tv;
}



/**
 * the turn of one of the players.
 */

void RealPlayer :: doOneTurn(GameRules *gameRules, Board &board,
                             vector<Coordinate> &coordinates,
                             Coordinate &input, BoardGraphic *boardGraphic, Player *player) {
    bool inputValid = false;
    while (!inputValid) {
        boardGraphic->printWhosMove(player);
        boardGraphic->printMoves(coordinates);
        boardGraphic->printSpecialSituation(AskForRowAndCol);


        while(!(cin>>input.row>>input.col)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            boardGraphic->printSpecialSituation(IllegelMove);
        }
        for (int i = 0; i < coordinates.size(); i++) {
           //checks if the input is one of the legal coordinates
            if (input.row == coordinates[i].row && input.col == coordinates[i].col) {
                inputValid = true;
                break;
            }
        }
        if (inputValid) {
            break;
        } else {

            boardGraphic->printSpecialSituation(IllegelMove);
        }
    }
}


bool RealPlayer :: isRealPlayer()const{
    return true;
}


