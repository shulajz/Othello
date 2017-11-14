//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_PLAYER_H
#define OTHELLO_PLAYER_H

#include "Cell.h"
#include "Board.h"
#include <vector>
using namespace std;
class GameRules;
class Player {
protected:
    TokenValue tv;
public:
    virtual void doOneTurn(GameRules *gameRules, Board *board,
                           vector<Coordinate> &coordinates, Coordinate &input) = 0;
    virtual void drawValue() const= 0;
    virtual TokenValue getValue() const;
    virtual void togglePlayer(TokenValue &tokenValue);
    virtual bool isWhitePlayer() const;

//    virtual TokenValue getOppositeValue(TokenValue tv) = 0;

};


#endif //OTHELLO_PLAYER_H
