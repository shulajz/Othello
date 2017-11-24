//
// Created by or on 11/23/17.
//


#include "Test_board.h"


TEST_F(Test_board,FullOfTokens){

    EXPECT_TRUE(board_2x2->isFullOfTokens()) << "the full of tokens test of 2x2 board failed";
}

