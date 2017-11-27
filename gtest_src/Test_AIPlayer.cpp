/*
 * ex3.c
 *
 *  Created on: Nov 16, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit: 313485690
*/

#include "Test_AIPlayer.h"
#include "Test_classicRules.h"

/**
 * testing the calcTheMaxScoreForOneTurn method.
 */
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
// one turn of the white.
    Coordinate testingCoordinate = {0};
    testingCoordinate.row = 3;
    testingCoordinate.col = 3;
    board_8x8.updateValue(testingCoordinate, White);
    classicRules.flipTokens(testingCoordinate, board_8x8, aiPlayerWhite);

    aiPlayerBlack->calcTheMaxScoreForOneTurn(&classicRules, board_8x8, validCoordinates, maxLocal);
    ASSERT_EQ(maxLocal, 3) << "calcTheMaxScoreForOneTurn test failed";
    delete(aiPlayerWhite);
    delete(aiPlayerBlack);

}
/**
 * Testing of do one turn.
 * check if in the regular board 8x8 with adding black coordinate
 * (3,4) to the board ,the AIPlayer choose the wright coordinate in this case (3,3).
 */
TEST_F(Test_AIPlayer, doOneTurn1){
    ConsoleBoard consoleBoard(9);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;
    Board board_8x8(9, consoleTokenFactory, consoleBoard,
                    classicRules.getInitialValues(9));
    Player* realPlayer= new RealPlayer(Black);
    Coordinate coordinate;
    Coordinate inputCoordinate;
    coordinate.row = 3;
    coordinate.col = 4;
    board_8x8.updateValue(coordinate,Black);
    classicRules.flipTokens(coordinate,board_8x8,realPlayer);
    vector<Coordinate> possibleCoordinates;
    classicRules.getLegalCoordinates(board_8x8, aiPlayerWhite, possibleCoordinates);
    aiPlayerWhite->doOneTurn(&classicRules,board_8x8,possibleCoordinates,
                             inputCoordinate, &consoleBoard, aiPlayerWhite);
    board_8x8.updateValue(inputCoordinate, White);
    classicRules.flipTokens(inputCoordinate,board_8x8, aiPlayerWhite);
    ASSERT_TRUE(board_8x8.getTokens()[3][3].isWhite())<<"doOneTurn test failed(1)";
    delete(realPlayer);
}
/**
 * Testing of do one turn.
 * check if in the regular board 8x8 with adding black coordinate
 * (5,6) to the board ,the AIPlayer choose the wright coordinate in this case (6,4).
 */
TEST_F(Test_AIPlayer, doOneTurn2){
    ConsoleBoard consoleBoard(9);
    ConsoleTokenFactory consoleTokenFactory;
    ClassicRules classicRules;

    Board board_8x8(9, consoleTokenFactory, consoleBoard,
                    classicRules.getInitialValues(9));
    Player* realPlayer= new RealPlayer(Black);
    Coordinate coordinate;
    Coordinate inputCoordinate;
    coordinate.row = 5;
    coordinate.col = 6;
    board_8x8.updateValue(coordinate,Black);
    classicRules.flipTokens(coordinate,board_8x8,realPlayer);
    vector<Coordinate> possibleCoordinates;
    classicRules.getLegalCoordinates(board_8x8, aiPlayerWhite, possibleCoordinates);
    aiPlayerWhite->doOneTurn(&classicRules,board_8x8,possibleCoordinates,inputCoordinate,
                             &consoleBoard,aiPlayerWhite);
    board_8x8.updateValue(inputCoordinate, White);
    classicRules.flipTokens(inputCoordinate,board_8x8, aiPlayerWhite);
    ASSERT_TRUE(board_8x8.getTokens()[6][4].isWhite())<<"doOneTurn test failed(1)";
    delete(realPlayer);
}