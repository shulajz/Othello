//
// Created by shulamit on 10/31/17.
//

#include "GameFlow.h"
#include <iostream>
#include <vector>


using namespace std;

GameFlow ::GameFlow(GameRules &gameRules, Player **players, Board &board, BoardGraphic &boardGraphic):
        m_gameRules(gameRules),m_board(board), m_boardGraphic(boardGraphic) {
    this->players = players;
//    this->currentTurn =players[Black]->getValue();//
    currentTurn = Black;
}


/**
 * where the game runs..
 */
void GameFlow :: run () {
    Coordinate inputCoordinate;
    inputCoordinate.row = 0;
    inputCoordinate.col = 0;
    bool first_move=true;
    bool needToPrint=true;
    while (true) {
        if (!printBoardIfNeed(needToPrint)) {
            break;
        }
        if (!first_move && (needToPrint)) {
            players[!currentTurn]->printWhatThePlayerPlayed(inputCoordinate,
                                                            &m_boardGraphic);
        }
        first_move = false;
        vector<Coordinate> validCoordinates;


        m_gameRules.getLegalCoordinates(m_board, players[currentTurn],
                                        validCoordinates);
        if (validCoordinates.empty()) {
            //switching to the other player in order to check
            // if he's got any legal moves
            players[currentTurn]->togglePlayer(currentTurn);
            m_gameRules.getLegalCoordinates(m_board, players[currentTurn],validCoordinates);
            if (validCoordinates.empty()) // checking if the other player has any legal moves
            { // there is no options for either of the players
                m_boardGraphic.printSpecialSituation(NoMovesForAll);
//                break;
            } else {
                players[currentTurn]->togglePlayer(currentTurn);
                m_boardGraphic.printWhosMove(currentTurn);
                m_boardGraphic.printSpecialSituation(Next); //no possible moves for one player
                needToPrint=false;
            }
        }
        else
        {
            players[currentTurn]->printAfterTheRealPlayerMove(&m_boardGraphic,needToPrint);
            players[currentTurn]->doOneTurn(&m_gameRules, m_board,
                                            validCoordinates, inputCoordinate, &m_boardGraphic,
                                            players[currentTurn]);
            m_board.updateValue(inputCoordinate, currentTurn);
            m_gameRules.flipTokens(inputCoordinate, m_board, players[currentTurn]);
            needToPrint=true;

        }
        players[currentTurn]->togglePlayer(currentTurn);

    }
    //func of print status
    int black = 0;
    int white = 0;
    m_board.calcResults(black, white);
    m_boardGraphic.drawStatus(black, white);
}

bool GameFlow::printBoardIfNeed(bool &needToPrint){
    //if the board full print and break.
    if (m_board.isFullOfTokens()) {
        m_board.draw();
        return false;
    }
    if ((needToPrint||players[currentTurn]->isRealPlayer())) {
        m_board.draw();
    }
    return true;
}