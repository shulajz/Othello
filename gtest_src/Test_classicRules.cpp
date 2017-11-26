/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:
*/

#include "Test_classicRules.h"
#include "../src/RealPlayer.h"

TEST_F(Test_classicRules, getlegalCoordinatesForEmptyBoard){
    vector<Coordinate> validCoordinates;
    classicRules.getLegalCoordinates(*board_8x8, realPlayer,
                                    validCoordinates);
    ASSERT_TRUE(validCoordinates[0].row ==  3 && validCoordinates[0].col == 4
                && validCoordinates[1].row ==  4 && validCoordinates[1].col == 3
                && validCoordinates[2].row ==  5 && validCoordinates[2].col == 6
                && validCoordinates[3].row ==  6 && validCoordinates[3].col == 5)
                                << "getLegalCoordinates for empty board test failed";
}

TEST_F(Test_classicRules, getlegalCoordinatesForFullBoard){
    vector<Coordinate> validCoordinates;
    classicRules.getLegalCoordinates(*board_2x2, realPlayer,
                                     validCoordinates);
    ASSERT_TRUE(validCoordinates.empty())
                                << "getLegalCorrdinates for full board test failed";
}

TEST_F(Test_classicRules, noValidMovesOnBoard){
    vector<Coordinate> validCoordinates;
    Coordinate testingCoordinate1 = {0};
    testingCoordinate1.row = 5;
    testingCoordinate1.col = 6;
    board_8x8->updateValue(testingCoordinate1, Black);
    classicRules.flipTokens(testingCoordinate1, *board_8x8, realPlayer);

    Coordinate testingCoordinate2 = {0};
    testingCoordinate1.row = 3;
    testingCoordinate1.col = 4;
    board_8x8->updateValue(testingCoordinate2, Black);
    classicRules.flipTokens(testingCoordinate1, *board_8x8, realPlayer);


    classicRules.getLegalCoordinates(*board_8x8, realPlayer,
                                     validCoordinates);
    ASSERT_TRUE(validCoordinates.empty())
                                << "noValidMovesOnBoard test failed";
}


TEST_F(Test_classicRules,checkIfCellValid) {
    TokenValue oppositeValue = classicRules.getOppositeValue(realPlayer);
    vector<Coordinate> validCoordinates;
    Token** tokens = board_8x8->getTokens();
    int dim = board_8x8->getDimensions();
    Coordinate testingCoordinate;
    testingCoordinate.row = 3;
    testingCoordinate.col = 4;

    classicRules.checkIfCellValid(tokens, testingCoordinate.row,
                                  testingCoordinate.col,
                                 1, 0,
                                 validCoordinates, dim,
                                 oppositeValue);
    ASSERT_TRUE(validCoordinates[0].row == 3 && validCoordinates[0].col == 4)
                                << "checkIfCellValid test failed";
}

TEST_F(Test_classicRules,checkIfToFlipCell) {
    vector<Coordinate> validCoordinates;
    Token** tokens = board_8x8->getTokens();
    int dim = board_8x8->getDimensions();
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 4;

    classicRules.checkIfToFlipCell(
            testingCoordinate, 1, 0, validCoordinates,
            dim, tokens, realPlayer);

    ASSERT_TRUE(validCoordinates[0].row == 4 && validCoordinates[0].col == 4)
                                << "checkIfToFlipCell test failed";
}

TEST_F(Test_classicRules, flipTokens) {

    ASSERT_TRUE(board_8x8->getTokens()[4][4].isWhite())
                                << "flipTokens test failed";
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 4;
    board_8x8->updateValue(testingCoordinate, Black);
    classicRules.flipTokens(testingCoordinate, *board_8x8, realPlayer);

    ASSERT_TRUE(board_8x8->getTokens()[4][4].isBlack())
                                << "flipTokens test failed";
}