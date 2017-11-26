//
// Created by shulamit on 10/30/17.
//

#ifndef OTHELLO_BOARD_H
#define OTHELLO_BOARD_H

#include "BoardGraphic.h"
#include "Token.h"
#include "TokenFactory.h"
#include "Cell.h"


class Board {
private:
    //Token** boardArr;


    Token** boardArr;
//    Cell* initialCells;
    BoardGraphic &m_boardGraphic;
    int dimensions;
    TokenFactory &pTokenFactory;

public:
    Board(int dimensions, TokenFactory &pTokenFactory,
          BoardGraphic &boardGraphic, Cell* initialCells);
    Board (Board &oldBoard);
    Token** getTokens() const;

    void draw() const;
    int getDimensions() const;
    bool isFullOfTokens() const; // checks if the board is full of tokens
    void updateValue(Coordinate coordinate, TokenValue tv);
    void calcResults(int &black, int &white);
    Board& operator=(const Board&);

    virtual ~Board();

};

#endif //OTHELLO_BOARD_H
