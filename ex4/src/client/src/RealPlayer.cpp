//
// Created by shulamit on 10/31/17.
////

#include "RealPlayer.h"

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

    gameRules->getLegalCoordinates(board, this,coordinates);
    if(coordinates.empty()) {
        //current player doesn't have a turn
        input.row = NoMove;
        input.col = NoMove;

    } else {
        bool inputValid = false;
        while (!inputValid) {
            boardGraphic->printWhosMove(player->getIdentity());
            boardGraphic->printMoves(coordinates);
            boardGraphic->printSpecialSituation(AskForRowAndCol);

            boardGraphic->receivePlayersAnswer(input);
            for (int i = 0; i < coordinates.size(); i++) {
                //checks if the input is one of the legal coordinates
                if (input.row == coordinates[i].row
                    && input.col == coordinates[i].col) {
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
}

bool RealPlayer :: isRealPlayer()const{
    return true;
}
