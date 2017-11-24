//
// Created by shulamit on 23/11/17.
//

#ifndef OTHELLO_TEST_BOARD_H
#define OTHELLO_TEST_BOARD_H

#include <gtest/gtest.h>
#include "../src/Board.h"
#include "../src/ConsoleBoard.h"
#include "../src/ConsoleTokenFactory.h"
#include "../src/ClassicRules.h"

class Test_board : public testing::Test {
public:
    virtual void SetUp() {

        ConsoleBoard consoleBoard(3);
        ConsoleTokenFactory consoleTokenFactory;
        ClassicRules classicRules;
        board_2x2 =new Board (3, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(3));;
        board_8x8 =new Board (9, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(9));;

    }
    virtual void TearDown() {
       delete(board_2x2);
       delete(board_8x8);
    }

protected:
     Board* board_2x2;
     Board* board_8x8;
};

#endif //OTHELLO_TEST_BOARD_H
