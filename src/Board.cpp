/*
 * Board.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: Shulamit
 */

using namespace std;


#include <vector>
#include <list>
#include <iostream>
#include "Board.h"
#include "TokenFactory.h"


/**
 *
 * @param dimensions - the dimentions of the board.
 * @param pTokenFactory - the token factory we're using to create tokens.
 * @param boardGraphic - the type of graphic we're using.
 * @param initialCells - the cells we need to init in the beginning.
 */
Board::Board(int dimensions, TokenFactory &pTokenFactory,
             BoardGraphic &boardGraphic, Cell* initialCells): m_boardGraphic(boardGraphic),
                                                              pTokenFactory(pTokenFactory){
    this->dimensions = dimensions;

    boardArr = new Token*[dimensions];
    for (int i = 0; i < dimensions; i++) {
        boardArr[i] = pTokenFactory.Create(dimensions);
    }

    //one teo three

    for(int i = 0; i < 4; i++) {
        //set values to the initial cells
        boardArr[initialCells[i].coordinate.row][initialCells[i].coordinate.col].
                setValue(initialCells[i].tv);
    }
    delete[] initialCells;

}

Board :: Board(Board &oldBoard): m_boardGraphic(oldBoard.m_boardGraphic),
                                 pTokenFactory(oldBoard.pTokenFactory){
    this->dimensions = oldBoard.dimensions;
    boardArr = new Token*[dimensions];

    for (int i = 0; i < dimensions; i++) {
        boardArr[i] = pTokenFactory.Create(dimensions);
    }
    for (int i = 1; i < dimensions; i++) {
        for (int j = 1; j < dimensions; j++) {
            boardArr[i][j] = oldBoard.boardArr[i][j];
        }
    }
}
/**
 * the destructor.
 */
Board::~Board() {
    for (int i = 0; i < dimensions; i++) {
        delete[] boardArr[i];
    }
    delete[] boardArr;
}

/**
 * @return the dimenstions of the board
 */
int Board :: getDimensions() const{
    return this->dimensions;
}
/**
 * Draws the board.
 */
void Board :: draw() const{
    m_boardGraphic.draw((Token**)boardArr);
}

/**
 * @return if the board is full - true, else false
 */
bool Board :: isFullOfTokens() const{

    for(int i = 1 ; i < dimensions; i++){
        for(int j = 1; j < dimensions; j++) {
            if (boardArr[i][j].isEmpty()) {
                return false;
            }
        }

    }
    return true;
}
/**
 * @return the array of tokens.
 */
Token** Board :: getTokens() const{
    return this->boardArr;

}
/**
 * @param coordinate - the coordinate to update
 * @param tv the tokenValue we're updating
 */
void Board ::updateValue(Coordinate coordinate, TokenValue tv) {
    boardArr[coordinate.row][coordinate.col].setValue(tv);
}
/**
 * calculates who wins the game.
 */
void Board:: calcResults(int &black, int &white) {
    for(int i = 1; i < dimensions; i ++) {
        for (int j = 1; j < dimensions; j++) {
            if (boardArr[i][j].getValue() == Black) {
                black++;
            } else if (boardArr[i][j].getValue() == White) {
                white++;
            } else if ((boardArr[i][j].getValue() == Empty)) {
                continue;
            }
        }
    }
}

//Board& operator=(const Board& copyBoard){
//    dimensions = copyBoard.dimensions;
//    boardArr = new Token*[dimensions];
//
//    for (int i = 0; i < dimensions; i++) {
//        boardArr[i] = pTokenFactory.Create(dimensions);
//    }
//    for (int i = 1; i < dimensions; i++) {
//        for (int j = 1; j < dimensions; j++) {
//            boardArr[i][j] = copyBoard.boardArr[i][j];
//        }
//    }
//    return *this;
//}
