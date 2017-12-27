//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_GAMERULES_H
#define OTHELLO_GAMERULES_H

#include "Cell.h"
#include "Player.h"
#include "Board.h"
#include <vector>

class GameRules {

public:
    virtual Cell* getInitialValues(int dim) const = 0;
    virtual void getLegalCoordinates(Board &b, Player *players,
                                     vector<Coordinate> &validCoordinates) = 0;
    virtual TokenValue getOppositeValue(Player* player) const  = 0;
    virtual void checkIfCellValid(Token **token, int row, int col,
                                  int rowDir, int colDir, vector<Coordinate> &pValidCoordinates,
                                  int dim, TokenValue opposite) = 0;
    virtual void checkIfToFlipCell(Coordinate inputCoordinate, int rowDir, int colDir,
                                   vector<Coordinate> &coordinatesToFlip, int dim, Token** tokens,
                                   Player *player) = 0;
    virtual void flipTokens(Coordinate inputCoordinate, Board &board, Player *player) = 0;
    virtual ~GameRules(){};
    //

};


#endif //OTHELLO_GAMERULES_H
