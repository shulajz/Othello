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
      Board board (3, consoleTokenFactory, consoleBoard, classicRules.getInitialValues(3));;

    }
    virtual void TearDown() {
        cout << "Tearing down" << endl;
    }

protected:
//    Board board;
};

#endif //OTHELLO_TEST_BOARD_H
