//
// Created by shulamit on 24/11/17.
//

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
        virtual void SetUp() {

            ConsoleBoard consoleBoard(3);
            ConsoleTokenFactory consoleTokenFactory;
            board_8x8 = new Board (9, consoleTokenFactory,
                                  consoleBoard, classicRules.getInitialValues(9));
            realPlayer = new RealPlayer(Black);

//            Board board_8x8(9, consoleTokenFactory,
//                            consoleBoard, classicRules.getInitialValues(9));

        }
        virtual void TearDown() {
            delete(board_8x8);
            delete(realPlayer);
        }

    protected:

        Player *realPlayer;
        Board* board_8x8;
        ClassicRules classicRules;

};


#endif //OTHELLO_TEST_CLASSICRULES_H
