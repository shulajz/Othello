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

    ConsoleBoard consoleBoard(DIM);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;
    Board board (DIM, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(DIM));
}
