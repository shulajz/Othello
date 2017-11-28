/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/

#include "Test_board.h"

/**
 * Testing the FullOfTokens method
 */
TEST_F(Test_board,FullOfTokens){

    EXPECT_TRUE(board_2x2->isFullOfTokens()) << "the full of tokens test of 2x2 board failed";
}
/**
 * Testing the calcResults method
 */
TEST_F(Test_board,calcResults) {
    Coordinate coordinate;
    coordinate.col = 3;
    coordinate.row = 3;
    TokenValue tv(White);
    board_8x8->updateValue(coordinate, tv);
    int black = 0, white = 0;
    board_8x8->calcResults(black, white);
    EXPECT_EQ(black, 2) << "the calcResult test failed(1)";
    EXPECT_EQ(white, 3) << "the calcResult test failed(2)";
}
/**
 * Testing  the get Dimensions.
 */
TEST_F(Test_board,getDimensions) {
    EXPECT_EQ(board_8x8->getDimensions(), DIM_9) << "the getDimensions test failed(1)";
    EXPECT_EQ(board_2x2->getDimensions(), DIM_3) << "the getDimensions test failed(2)";
}
