//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_PLAYER_H
#define OTHELLO_PLAYER_H

#include "Cell.h"
//#include "Board.h"
//#include "BoardGraphic.h"
#include <vector>
using namespace std;
class GameRules;
class Board;
class BoardGraphic;

class Player {
protected:
    TokenValue tv;
public:
    virtual void doOneTurn(GameRules *gameRules, Board &board,
                           vector<Coordinate> &coordinates,
                           Coordinate &input, BoardGraphic *boardGraphic, Player *player) =0;
    virtual TokenValue getValue() const;
    virtual void togglePlayer(TokenValue &tokenValue);
    virtual bool isWhitePlayer() const;
    virtual void printWhatThePlayerPlayed(Coordinate coordinate, BoardGraphic *boardGraphic);
    virtual void printAfterTheRealPlayerMove(BoardGraphic *boardGraphic,bool need_to_print) const;
    virtual bool isRealPlayer()const=0;
    virtual void calcTheMaxScoreForOneTurn(GameRules *gameRules, Board &tempBoard,
                                   vector<Coordinate> &validCoordinates, int &maxLocal){};
    TokenValue getIdentity();

};


#endif //OTHELLO_PLAYER_H
