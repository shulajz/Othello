//
// Created by or on 11/23/17.
//


#include "Test_board.h"


TEST_F(Test_board,FullOfTokens){

    EXPECT_TRUE(board_2x2->isFullOfTokens()) << "the full of tokens test of 2x2 board failed";
}

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

TEST_F(Test_board,getDimensions) {
    EXPECT_EQ(board_8x8->getDimensions(), 9) << "the getDimensions test failed(1)";
    EXPECT_EQ(board_2x2->getDimensions(), 3) << "the getDimensions test failed(2)";
}

