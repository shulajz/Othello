/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/

#ifndef OTHELLO_TEST_CLASSICRULES_H
#define OTHELLO_TEST_CLASSICRULES_H


#include <gtest/gtest.h>
#include "../src/ConsoleBoard.h"
#include "../src/Board.h"
#include "../src/ConsoleTokenFactory.h"
#include "../src/ClassicRules.h"
#include "../src/RealPlayer.h"
#define DIM_3 3
#define DIM_9 9
class Test_classicRules : public testing::Test {
public:
        virtual void SetUp() {

            ConsoleBoard consoleBoard1(DIM_3);
            ConsoleBoard consoleBoard2(DIM_9);
            ConsoleTokenFactory consoleTokenFactory;
            board_8x8 = new Board (DIM_9, consoleTokenFactory,
                                   consoleBoard2, classicRules.getInitialValues(DIM_9));
            realPlayer = new RealPlayer(Black);
            board_2x2 = new Board (DIM_3, consoleTokenFactory, consoleBoard1,
                                  classicRules.getInitialValues(DIM_3));


        }
        virtual void TearDown() {
            delete(board_2x2);
            delete(board_8x8);
            delete(realPlayer);
        }

    protected:

        Player *realPlayer;
        Board* board_8x8;
        Board* board_2x2;
        ClassicRules classicRules;

};


#endif //OTHELLO_TEST_CLASSICRULES_H
