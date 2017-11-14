//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_CONSOLEBOARD_H
#define OTHELLO_CONSOLEBOARD_H


#include "BoardGraphic.h"

class ConsoleBoard : public BoardGraphic{

private:
    int dimensions;
public:
    ConsoleBoard(int dimensions);
    //draws the board
    virtual void draw(Token** tokenArr) const;
};


#endif //OTHELLO_CONSOLEBOARD_H
