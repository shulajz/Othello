/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:
*/
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

        ConsoleBoard consoleBoard1(3);
        ConsoleBoard consoleBoard2(9);
        ConsoleTokenFactory consoleTokenFactory;
        ClassicRules classicRules;
        board_2x2 = new Board (3, consoleTokenFactory, consoleBoard1, classicRules.getInitialValues(3));;
        board_8x8 = new Board (9, consoleTokenFactory, consoleBoard2, classicRules.getInitialValues(9));;
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