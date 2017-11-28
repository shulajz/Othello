//
// Created by shulamit on 10/30/17.
//

#ifndef OTHELLO_BOARDGRAPHIC_H
#define OTHELLO_BOARDGRAPHIC_H

#include "Token.h"
#include "Player.h"
//#include "Tools.h"



class BoardGraphic {
public:
    virtual void draw(Token** tokenArr) const = 0;
    virtual void printSpecialSituation(Situation message) const = 0;
    virtual void printWhosMove(Player *player) const = 0;
    /**
     * print the valid moves of the player.
     * @param validCoordinates
     */
    virtual void printMoves(vector<Coordinate> validCoordinates) const;
    /**
     * Print who wins the game.
     * @param black
     * @param white
     */
    virtual void drawStatus(int black, int white) const = 0;
    virtual void printThePlayersChoice(Coordinate coordinate, Player *player) const;
    virtual void printAfterRealPlayer() const;
};

#endif //OTHELLO_BOARDGRAPHIC_H
