//
// Created by or on 13/8/17.
//

#include "GameFlow.h"
GameFlow ::GameFlow (GameRules &gameRules, Player **players, Board &board, BoardGraphic &boardGraphic):
        m_gameRules(gameRules),m_board(board), m_boardGraphic(boardGraphic),
        first_move(true), needToPrint(true), thereIsAMoveForOnePlayer(true) ,turn (Black),
        noMove(false) {
    this->players = players;
    curr_player = players[Black];
    inputCoordinate.row = 0;
    inputCoordinate.col = 0;
}

/**
 * where the game runs...
 */
void GameFlow :: run () {
    //while the board not full or there is no possible moves running the game
    while (!m_board.isFullOfTokens() && thereIsAMoveForOnePlayer) {
        playOneTurn();
    }
    // update the server that its the end of the game
    curr_player->sendEndOfGame(inputCoordinate);

    //print after the game end the current board if needToPrint is not false
    // (happened when there is no moves for both players and the board we print
    // in the last time is the same so we don't want to print the board again).
    if (needToPrint) {
        m_board.draw();
        //if is not the first move print what the rival played
        if(!first_move) {
            players[!curr_player->getValue()]->
                    printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
        }
    }
    printStatus();
}

//print number of white and number of black and
//announcement of the winner in the game
void GameFlow :: printStatus(){
    int black = 0;
    int white = 0;
    m_board.calcResults(black, white);
    m_boardGraphic.drawStatus(black, white);
}

void GameFlow :: playOneTurn(){
    //print board unless there is no possible move for the previous player
    if ((needToPrint || curr_player->isRealPlayer())) {
        m_board.draw();
        //print the moves that rival did.
        if (!first_move && (needToPrint)
            && !players[!curr_player->getValue()]->isRealPlayer()) {
            if (inputCoordinate.row != NoMove)
            {
                players[!curr_player->getValue()]->
                        printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
            }
            curr_player->printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
        }
    }
    first_move = false;
    //find the possible moves  depending on the game rules.
    vector<Coordinate> validCoordinates;
    m_gameRules.getLegalCoordinates(m_board, curr_player, validCoordinates);
    if (!validCoordinates.empty() || rivalHasAMove()) {
        //if one of the players can play
        handleOnePlayerHasAMove(validCoordinates);
    } else {
        //if we don't have possible moves
        thereIsAMoveForOnePlayer = false;
        needToPrint = false;
        m_boardGraphic.printSpecialSituation(NoMovesForAll);
    }
    switchPlayer();

}

bool GameFlow :: rivalHasAMove() {
    vector<Coordinate> legalCoordinates;
    switchPlayer();
    m_gameRules.getLegalCoordinates(m_board, curr_player, legalCoordinates);
    if (legalCoordinates.empty()) {
        //other player doesnt have move
        return false;
    } else {
        //other player DOES have a move
        switchPlayer();
        return true;
    }

}

void GameFlow ::handleOnePlayerHasAMove(vector<Coordinate>& validCoordinates) {
    curr_player->printAfterTheRealPlayerMove(&m_boardGraphic,needToPrint);
    //do the turn of the player depend of is type: RemotePlayer, AIPlayer or RealPlayer.
    curr_player->doOneTurn(&m_gameRules, m_board, validCoordinates,
                           inputCoordinate, &m_boardGraphic, curr_player);
    //check if there is valid coordinates if so, update the value of the inputCoordinate in the board
    //and flip tokens.
    if(inputCoordinate.row > 0 && inputCoordinate.col > 0){
        m_board.updateValue(inputCoordinate, curr_player->getValue());
        m_gameRules.flipTokens(inputCoordinate, m_board, curr_player);
    }
    needToPrint = true;
    if (inputCoordinate.row == NoMove && inputCoordinate.col == NoMove){
        needToPrint = false;
    }
}

void GameFlow:: switchPlayer(){
    if (curr_player == players[turn]){
        curr_player = players[!turn];
    }else{
        curr_player = players[turn];
    }
}