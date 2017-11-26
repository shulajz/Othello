//
// Created by shulamit on 25/11/17.
//

#include "Test_AIPlayer.h"
#include "Test_classicRules.h"



TEST_F(Test_AIPlayer, calcTheMaxScoreForOneTurn){
    vector<Coordinate> validCoordinates;
    int maxLocal = 0;
    Player *aiPlayerWhite = new AIPlayer(White);
    Player *aiPlayerBlack = new AIPlayer(Black);

    ConsoleBoard consoleBoard(9);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;

    Board board_8x8(9, consoleTokenFactory, consoleBoard,
                    classicRules.getInitialValues(9));
//flip the blacks first
    Coordinate testingCoordinate1 = {0};
    testingCoordinate1.row = 3;
    testingCoordinate1.col = 4;
    board_8x8.updateValue(testingCoordinate1, Black);
    classicRules.flipTokens(testingCoordinate1, board_8x8, aiPlayerBlack);
// one turn of the white
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 3;
    board_8x8.updateValue(testingCoordinate, White);
    classicRules.flipTokens(testingCoordinate, board_8x8, aiPlayerWhite);

    aiPlayerBlack->calcTheMaxScoreForOneTurn(&classicRules, board_8x8, validCoordinates, maxLocal);
    ASSERT_EQ(maxLocal, 3) << "calcTheMaxScoreForOneTurn test failed";
}