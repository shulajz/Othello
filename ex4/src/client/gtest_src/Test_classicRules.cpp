/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/

#include "Test_classicRules.h"
/**
 * Testing getLegalCoordinates method for an empty board.
 */
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
/**
 * Testing getLegalCoordinates method for a full board
 */
TEST_F(Test_classicRules, getlegalCoordinatesForFullBoard){
    vector<Coordinate> validCoordinates;
    classicRules.getLegalCoordinates(*board_2x2, realPlayer,
                                     validCoordinates);
    ASSERT_TRUE(validCoordinates.empty())
                                << "getLegalCoordinates for full board test failed";
}
/**
 * Testing the method getLegalCoordinates when there are
 * no valid moves left.
 */
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
/**
 * Testing the method of checkIfCellValid.
 */
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
/**
 * Testing the method of checkIfToFlipCell.
 */
TEST_F(Test_classicRules,checkIfToFlipCell) {
    vector<Coordinate> validCoordinates;
    Token** tokens = board_8x8->getTokens();
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 4;

    classicRules.checkIfToFlipCell(
            testingCoordinate, 1, 0, validCoordinates,
            DIM, tokens, realPlayer);

    ASSERT_TRUE(validCoordinates[0].row == 4
                && validCoordinates[0].col == 4)
                                << "checkIfToFlipCell test failed";
}
/**
 * Testing the method of flipTokens.
 */
TEST_F(Test_classicRules, flipTokens) {

    ASSERT_TRUE(board_8x8->getTokens()[4][4].isWhite())
                                << "flipTokens test failed(1)";
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 4;
    board_8x8->updateValue(testingCoordinate, Black);
    classicRules.flipTokens(testingCoordinate, *board_8x8, realPlayer);
    ASSERT_TRUE(board_8x8->getTokens()[4][4].isBlack())
                                << "flipTokens test failed(2)";
}

/**
 * Testing getlegalCoordinate method after a simple move.
 */
TEST_F(Test_classicRules, getlegalCoordinatesForASimpleMove){
    Player* whitePlayer = new RealPlayer(White);
    vector<Coordinate> validCoordinates;
    Coordinate coordinate;
    coordinate.row=5;
    coordinate.col=6;
    board_8x8->updateValue(coordinate, Black);
    classicRules.flipTokens(coordinate,*board_8x8,realPlayer);
    classicRules.getLegalCoordinates(*board_8x8, whitePlayer,
                                     validCoordinates);
    ASSERT_TRUE(validCoordinates[0].row ==  4 && validCoordinates[0].col == 6
                && validCoordinates[1].row ==  6 && validCoordinates[1].col == 4
                && validCoordinates[2].row ==  6 && validCoordinates[2].col == 6)
                                << "getlegalCoordinatesForASimpleMove test failed";
    delete(whitePlayer);
}

/**
 * Testing getlegalCoordinate method when theres only one option
 * available for the player.
 */
TEST_F(Test_classicRules, getlegalCoordinateWithOneOptionAvailable){
    Player* whitePlayer = new RealPlayer(White);
    vector<Coordinate> validCoordinates;
    Coordinate coordinate;
    coordinate.row=5;
    coordinate.col=6;
    board_8x8->updateValue(coordinate, Black);
    classicRules.flipTokens(coordinate,*board_8x8,realPlayer);
    coordinate.row=4;
    coordinate.col=3;
    board_8x8->updateValue(coordinate, Black);
    classicRules.flipTokens(coordinate,*board_8x8,realPlayer);
    coordinate.row=4;
    coordinate.col=2;
    board_8x8->updateValue(coordinate, White);
    classicRules.flipTokens(coordinate,*board_8x8,whitePlayer);
    classicRules.getLegalCoordinates(*board_8x8,whitePlayer ,
                                     validCoordinates);
    ASSERT_TRUE(validCoordinates[0].row ==  4 && validCoordinates[0].col == 6)
                                << "getlegalCoordinateWithOneOptionAvailable test failed";
    delete(whitePlayer);

}