//
// Created by shulamit on 10/30/17.
//

#ifndef OTHELLO_BOARDGRAPHIC_H
#define OTHELLO_BOARDGRAPHIC_H

#include "Token.h"
#include "Player.h"
#include "Tools.h"

class BoardGraphic {
public:
    virtual void draw(Token** tokenArr) const = 0;
    virtual void printSpecialSituation(Situation message) const = 0;
    virtual void printWhosMove(Player *player) const = 0;
    virtual void printMoves(vector<Coordinate> validCoordinates) const;
    virtual void drawStatus(int black, int white) const = 0;
    virtual void printThePlayersChoice(Coordinate coordinate, Player *player) const;
    virtual void printAfterRealPlayer() const;



};

#endif //OTHELLO_BOARDGRAPHIC_H
