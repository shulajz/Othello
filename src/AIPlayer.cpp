/*
 * ex3.c
 *
 *  Created on: Nov 16, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:
*/
#include <iostream>
#include "AIPlayer.h"
AIPlayer :: AIPlayer(TokenValue tv) {
    this->tv = tv;
}
void AIPlayer :: doOneTurn(GameRules *gameRules, Board &board,
                   vector<Coordinate> &coordinates, Coordinate &input,
                           BoardGraphic *boardGraphic, Player *player)  {
    vector<int> minOfAllMoves;
    Coordinate computerMove;

    for(int i = 0; i < coordinates.size(); i++) {
        vector<Coordinate> validCoordinates;
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

}

void AIPlayer :: calcTheMaxScoreForOneTurn(GameRules *gameRules, Board &tempBoard,
                                           vector<Coordinate> &validCoordinates, int &maxLocal) {

    gameRules->getLegalCoordinates(tempBoard, this, validCoordinates);
    for(int j = 0; j < validCoordinates.size(); j++) {
        int maxOfOneTurn = 0;
        Coordinate realPlayerMove;
        realPlayerMove.row = validCoordinates[j].row;
        realPlayerMove.col = validCoordinates[j].col;
        Board tempBoard2(tempBoard);
        tempBoard2.updateValue(realPlayerMove,tv);
        gameRules->flipTokens(realPlayerMove, tempBoard2, this);
        int numOfRealPlayerTokens = 0;
        int numOfComputerTokens = 0;
        tempBoard2.calcResults(numOfRealPlayerTokens, numOfComputerTokens);
        maxOfOneTurn = numOfRealPlayerTokens - numOfComputerTokens;
        if(maxLocal < maxOfOneTurn) {
            maxLocal = maxOfOneTurn;
        }
    }
}

void AIPlayer :: printWhatThePlayerPlayed(Coordinate coordinate, BoardGraphic *boardGraphic) {
    boardGraphic->printThePlayersChoice(coordinate, this);
}

void AIPlayer :: printAfterTheRealPlayerMove(BoardGraphic *boardGraphic,bool need_to_print) const {
    if (need_to_print){
        boardGraphic->printAfterRealPlayer();
    }
}

bool AIPlayer:: isRealPlayer()const{
    return true;
}