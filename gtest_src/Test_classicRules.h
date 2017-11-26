/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:
*/

#ifndef OTHELLO_TEST_CLASSICRULES_H
#define OTHELLO_TEST_CLASSICRULES_H


#include <gtest/gtest.h>
#include "../src/ConsoleBoard.h"
#include "../src/Board.h"
#include "../src/ConsoleTokenFactory.h"
#include "../src/ClassicRules.h"
#include "../src/RealPlayer.h"

class Test_classicRules : public testing::Test {
public:
//    Test_classicRules() :
//            ClassicRules classicRules;
//    ConsoleBoard consoleBoard(3),
//                          board_8x8(9, consoleTokenFactory,
//                                    consoleBoard, classicRules.getInitialValues(9));,
//                          board_2x2,
        virtual void SetUp() {

            ConsoleBoard consoleBoard1(3);
            ConsoleBoard consoleBoard2(9);
            ConsoleTokenFactory consoleTokenFactory;
            board_8x8 = new Board (9, consoleTokenFactory,
                                   consoleBoard2, classicRules.getInitialValues(9));
            realPlayer = new RealPlayer(Black);
            board_2x2 = new Board (3, consoleTokenFactory, consoleBoard1,
                                  classicRules.getInitialValues(3));


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
