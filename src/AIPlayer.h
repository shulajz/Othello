/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:
*/

#ifndef OTHELLO_AIPLAYER_H
#define OTHELLO_AIPLAYER_H


#include "Cell.h"
#include "Board.h"
#include "GameRules.h"

class AIPlayer : public Player{

    public:
    bool isRealPlayer()const;
    AIPlayer(TokenValue tv);
    virtual void doOneTurn(GameRules *gameRules, Board &board,
                           vector<Coordinate> &coordinates, Coordinate &input,
                           BoardGraphic *boardGraphic, Player *player);
    virtual void printWhatThePlayerPlayed(Coordinate coordinate, BoardGraphic *boardGraphic);
    virtual void calcTheMaxScoreForOneTurn(GameRules *gameRules, Board &tempBoard,
                                   vector<Coordinate> &validCoordinates, int &maxLocal);
    void printAfterTheRealPlayerMove(BoardGraphic *boardGraphic, bool need_to_print) const;
};


#endif //OTHELLO_AIPLAYER_H
