/*
 * ex3.c
 *
 *  Created on: Nov 16, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:
*/

#include "Test_AIPlayer.h"
#include "Test_classicRules.h"

TEST_F(Test_AIPlayer, doOneTurn1){
    ClassicRules classicRules;
    Player* realPlayer= new RealPlayer(Black);
    Coordinate coordinate;
    Coordinate inputCoordinate;
    coordinate.row = 3;
    coordinate.col = 4;
    board_8x8->updateValue(coordinate,Black);
    classicRules.flipTokens(coordinate,*board_8x8,realPlayer);
    vector<Coordinate> possibleCoordinates;
    classicRules.getLegalCoordinates(*board_8x8, aiPlayer, possibleCoordinates);
    aiPlayer->doOneTurn(&classicRules,*board_8x8,possibleCoordinates,inputCoordinate,&board_8x8->getBoardGraphic(),aiPlayer);
    board_8x8->updateValue(inputCoordinate, White);
    classicRules.flipTokens(inputCoordinate,*board_8x8, aiPlayer);
    ASSERT_TRUE(board_8x8->getTokens()[3][3].isWhite())<<"doOneTurn test failed(1)";
    delete(realPlayer);
}

TEST_F(Test_AIPlayer, doOneTurn2){
    ClassicRules classicRules;
    Player* realPlayer= new RealPlayer(Black);
    Coordinate coordinate;
    Coordinate inputCoordinate;
    coordinate.row = 5;
    coordinate.col = 6;
    board_8x8->updateValue(coordinate,Black);
    classicRules.flipTokens(coordinate,*board_8x8,realPlayer);
    vector<Coordinate> possibleCoordinates;
    classicRules.getLegalCoordinates(*board_8x8, aiPlayer, possibleCoordinates);
    aiPlayer->doOneTurn(&classicRules,*board_8x8,possibleCoordinates,inputCoordinate,&board_8x8->getBoardGraphic(),aiPlayer);
    board_8x8->updateValue(inputCoordinate, White);
    classicRules.flipTokens(inputCoordinate,*board_8x8, aiPlayer);
    ASSERT_TRUE(board_8x8->getTokens()[6][4].isWhite())<<"doOneTurn test failed(1)";
    delete(realPlayer);
}

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
