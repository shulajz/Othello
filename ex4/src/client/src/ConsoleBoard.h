//
// Created by shulamit on 10/31/17.
////

#ifndef OTHELLO_CONSOLEBOARD_H
#define OTHELLO_CONSOLEBOARD_H


#include "BoardGraphic.h"
#include "Player.h"
#include "Tools.h"

class ConsoleBoard : public BoardGraphic{

private:
    int dimensions;
public:
    ConsoleBoard(int dimensions);
    //draws the board
    virtual void draw(Token** tokenArr) const;
    virtual void printSpecialSituation(Situation message) const;
    virtual void printWhosMove(TokenValue tv) const;
    void printMoves(vector<Coordinate> validCoordinates) const;
    virtual void drawStatus(int black, int white)const;
    virtual void printThePlayersChoice(TokenValue tv, Coordinate coordinate) const;
    void printAfterRealPlayer() const;
    virtual void receivePlayersAnswer(Coordinate &input);
    virtual void printPlayersIdentity(TokenValue tv) const;


};


#endif //OTHELLO_CONSOLEBOARD_H
