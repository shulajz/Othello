//
// Created by or on 11/23/17.
//

#include "gtest/gtest.h"
#include "../src/Board.h"
#include "../src/ConsoleBoard.h"
#include "../src/ConsoleTokenFactory.h"
#include "../src/ClassicRules.h"

//#include "../src/Tools.h"

TEST(BoardTest,FullOfTokens){

    ConsoleBoard consoleBoard(3);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;
    Board board (3, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(3));
    EXPECT_TRUE(board.isFullOfTokens()) << "the full of tokens test failed";

}
