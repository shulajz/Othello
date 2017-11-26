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

        ConsoleBoard consoleBoard(9);
        ConsoleTokenFactory consoleTokenFactory;
        ClassicRules classicRules;
        aiPlayerWhite = new AIPlayer(White);
    }
    virtual void TearDown() {
        delete(aiPlayerWhite);
    }

protected:
    Player* aiPlayerWhite;
};


#endif //OTHELLO_TEST_AIPLAYER_H
