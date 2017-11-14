//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_REALPLAYER_H
#define OTHELLO_REALPLAYER_H


#include "RealPlayer.h"
#include "Tools.h"
#include "GameRules.h"
using namespace std;

class RealPlayer : public Player {


public:

    RealPlayer(TokenValue tv);
    //the turn of one of the players
    virtual void doOneTurn(GameRules *gameRules, Board *board,
                   vector<Coordinate> &coordinates, Coordinate &input);
    //draws the value
    virtual void drawValue() const;
};


#endif //OTHELLO_REALPLAYER_H
