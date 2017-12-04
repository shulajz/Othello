//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REMOTEPLAYER_H
#define OTHELLO_REMOTEPLAYER_H

#include "Player.h"


class RemotePlayer: public Player {
public:
    RemotePlayer(TokenValue tv);
    virtual void doOneTurn(GameRules *gameRules, Board &board,
                           vector<Coordinate> &coordinates,
                           Coordinate &input, BoardGraphic *boardGraphic, Player *player);
//    virtual bool isRealPlayer()const;
    bool isRemotePlayer() const;
};


#endif //OTHELLO_REMOTEPLAYER_H