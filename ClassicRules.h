//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_CLASSICRULES_H
#define OTHELLO_CLASSICRULES_H
#include <vector>

using namespace std;
#include "Board.h"
#include "GameRules.h"
#include "Cell.h"
#include "Player.h"
//#include "Coordinate.h"


class ClassicRules : public GameRules{
public:
    virtual Cell* getInitialValues(int dim) const;
    //get legal coordinates for the player
    virtual void getLegalCoordinates (Board &b, Player *player,
                                      vector<Coordinate> &validCoordinates);
    virtual void checkIfCellValid(Token **token, int row, int col,
                          int rowDir, int colDir, vector<Coordinate> &pValidCoordinates,
                                  int dim, TokenValue opposite);
    virtual TokenValue getOppositeValue(Player* player) const;
    virtual void checkIfToFlipCell(Coordinate inputCoordinate, int rowDir, int colDir,
                           vector<Coordinate> &coordinatesToFlip,
                                   int dim, Token** tokens, TokenValue oppositeValue);
    virtual void flipTokens(Coordinate inputCoordinate, Board &board, Player *player );

};


#endif //OTHELLO_CLASSICRULES_H
