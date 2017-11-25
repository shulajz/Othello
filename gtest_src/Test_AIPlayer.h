//
// Created by shulamit on 25/11/17.
//

#ifndef OTHELLO_TEST_AIPLAYER_H
#define OTHELLO_TEST_AIPLAYER_H


#include <gtest/gtest.h>
#include "../src/ConsoleBoard.h"
#include "../src/Board.h"
#include "../src/ConsoleTokenFactory.h"
#include "../src/ClassicRules.h"
#include "../src/AIPlayer.h"

class Test_AIPlayer : public testing::Test {
public:
    virtual void SetUp() {

        ConsoleBoard consoleBoard(3);
        ConsoleTokenFactory consoleTokenFactory;
        ClassicRules classicRules;
        Player *aiPlayer = new AIPlayer(Black);

        board_8x8 = new Board (9, consoleTokenFactory, consoleBoard,
                              classicRules.getInitialValues(9));

    }
    virtual void TearDown() {
//        delete(board_2x2);
        delete(aiPlayer);
        delete(board_8x8);
    }

protected:
    Player* aiPlayer;
    ClassicRules classicRules;
    Board* board_8x8;
};


#endif //OTHELLO_TEST_AIPLAYER_H
