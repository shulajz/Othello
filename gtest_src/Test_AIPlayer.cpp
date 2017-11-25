//
// Created by shulamit on 25/11/17.
//

#include "Test_AIPlayer.h"
#include "Test_classicRules.h"


//calcTheMaxScoreForOneTurn(GameRules *gameRules, Board &tempBoard,
//        vector<Coordinate> &validCoordinates, int &maxLocal)


TEST_F(Test_AIPlayer, calcTheMaxScoreForOneTurn){
    vector<Coordinate> validCoordinates;
    RealPlayer* realPlayer = new RealPlayer(Black);
    int maxLocal = 0;
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 4;
    board_8x8->updateValue(testingCoordinate, Black);
    classicRules.flipTokens(testingCoordinate, *board_8x8, realPlayer);
    aiPlayer->calcTheMaxScoreForOneTurn(&classicRules, *board_8x8, validCoordinates, maxLocal);
    ASSERT_EQ(maxLocal, 5) << "calcTheMaxScoreForOneTurn test failed";
}