//
// Created by shulamit on 16/11/17.
//

#include <iostream>
#include "AIPlayer.h"
AIPlayer :: AIPlayer(TokenValue tv) {
    this->tv = tv;
}
void AIPlayer :: doOneTurn(GameRules *gameRules, Board &board,
                   vector<Coordinate> &coordinates, Coordinate &input,
                           BoardGraphic *boardGraphic, Player *player)  {
    vector<int> minOfAllMoves;
    vector<Coordinate> validCoordinates;
    Coordinate computerMove;

    for(int i = 0; i < coordinates.size(); i++) {
        computerMove.row = coordinates[i].row;
        computerMove.col = coordinates[i].col;
        Board tempBoard(board);
        //making changes for a fake board,
        // each time with a different move
        tempBoard.updateValue(computerMove, tv);
        gameRules->flipTokens(computerMove, tempBoard, this);
        this->togglePlayer(tv); //now its the real players turn
        int maxLocal = 0;
        calcTheMaxScoreForOneTurn(gameRules, tempBoard,
                                  validCoordinates,maxLocal);
        minOfAllMoves.push_back(maxLocal);
        this->togglePlayer(tv); //now its the computers turn
    }
    int minOfAllMovesParam = minOfAllMoves[0];
    input.row = coordinates[0].row;
    input.col = coordinates[0].col;
    for(int k = 0; k < minOfAllMoves.size(); k++) {
        if(minOfAllMoves[k] < minOfAllMovesParam) {
            minOfAllMovesParam = minOfAllMoves[k];
            input.row = coordinates[k].row;
            input.col = coordinates[k].col;

        }
    }
//    this->togglePlayer(tv);

}

void AIPlayer :: calcTheMaxScoreForOneTurn(GameRules *gameRules, Board &tempBoard,
                                           vector<Coordinate> &validCoordinates, int &maxLocal) {
    int maxOfOneTurn = 0;

    gameRules->getLegalCoordinates(tempBoard, this, validCoordinates);
    for(int j = 0; j < validCoordinates.size(); j++) {
        Coordinate realPlayerMove;
        realPlayerMove.row = validCoordinates[j].row;
        realPlayerMove.col = validCoordinates[j].col;
        tempBoard.updateValue(realPlayerMove,tv);
        gameRules->flipTokens(realPlayerMove, tempBoard, this);
        int numOfRealPlayerTokens = 0;
        int numOfComputerTokens = 0;
        tempBoard.calcResults(numOfRealPlayerTokens, numOfComputerTokens);
        maxOfOneTurn = numOfRealPlayerTokens - numOfComputerTokens;
        if(maxLocal < maxOfOneTurn) {
            maxLocal = maxOfOneTurn;
        }
    }
}
