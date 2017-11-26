//
// Created by shulamit on 25/11/17.
//

#include "Test_AIPlayer.h"
#include "Test_classicRules.h"


//calcTheMaxScoreForOneTurn(GameRules *gameRules, Board &tempBoard,
//        vector<Coordinate> &validCoordinates, int &maxLocal)


TEST_F(Test_AIPlayer, calcTheMaxScoreForOneTurn){
    vector<Coordinate> validCoordinates;
    Player* realPlayer = new RealPlayer(Black);
    int maxLocal = 0;
    Player *aiPlayer1 = new AIPlayer(White);
    //flip the blacks first
    Coordinate testingCoordinate1 = {0};
    testingCoordinate1.row = 3;
    testingCoordinate1.col = 4;
    board_8x8->updateValue(testingCoordinate1, Black);
    classicRules.flipTokens(testingCoordinate1, *board_8x8, realPlayer);
    // one turn of the white
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 3;

    board_8x8->updateValue(testingCoordinate, White);
    classicRules.flipTokens(testingCoordinate, *board_8x8, aiPlayer1);


    aiPlayer1->calcTheMaxScoreForOneTurn(&classicRules, *board_8x8, validCoordinates, maxLocal);
    ASSERT_EQ(maxLocal, 5) << "calcTheMaxScoreForOneTurn test failed";
    delete(realPlayer);
}