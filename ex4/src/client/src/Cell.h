//
// Created by shulamit on 10/31/17.
////

#ifndef OTHELLO_CELL_H
#define OTHELLO_CELL_H

#include "Tools.h"

struct Coordinate {
    int row;
    int col;
};


struct Cell {
    Coordinate coordinate;
    TokenValue tv;
};





#endif //OTHELLO_CELL_H
