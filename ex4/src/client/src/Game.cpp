//
// Created by or on 13/8/17.
//

#include "Game.h"
Game ::Game(GameRules &gameRules, Player **players, Board &board, BoardGraphic &boardGraphic):
        m_gameRules(gameRules),m_board(board), m_boardGraphic(boardGraphic),
        first_move(true), needToPrint(true), noMovesForAll(false) ,turn (Black), noMove(false)  {
    this->players = players;
    curr_player = players[Black];
    inputCoordinate.row = 0;
    inputCoordinate.col = 0;
}

/**
 * where the game runs...
 */
void Game :: run () {
    //while the board not full or there is no possible moves running the game
    while (!m_board.isFullOfTokens() && !noMovesForAll) {
        playOneTurn();
    }
    // update the players that its the end of the game
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
void Game :: printStatus(){
    int black = 0;
    int white = 0;
    m_board.calcResults(black, white);
    m_boardGraphic.drawStatus(black, white);
}

void Game :: playOneTurn(){
    //print board unless there is no possible move for the previous player
    if ((needToPrint||curr_player->isRealPlayer())) {
        m_board.draw();
        //print the move that rival do.
        if (!first_move && (needToPrint)
            && !players[!curr_player->getValue()]->isRealPlayer()) {
            if (inputCoordinate.row != NoMove) {
                players[!curr_player->getValue()]->
                        printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
            }
            curr_player->printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
        }
    }
    first_move = false;
    //find the possible moves  depend on the game rules.
    vector<Coordinate> validCoordinates;
    m_gameRules.getLegalCoordinates(m_board, curr_player, validCoordinates);
    if (!validCoordinates.empty()){
        //if we  have possible moves
        ifValidCoordinates(validCoordinates);
    } else {
        //if we don't have possible moves
        ifNoValidCoordinates(validCoordinates);
    }
    switchPlayer();

}

void Game ::ifValidCoordinates(vector<Coordinate>& validCoordinates) {
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
        switchPlayer();
        needToPrint = false;
    }
}

void Game::ifNoValidCoordinates(vector<Coordinate>& validCoordinates) {
    //switching to the other player in order to check
    // if he's got any legal moves
    if(!curr_player->isRealPlayer()) {
        noMove = true;
    }
    switchPlayer();
    m_gameRules.getLegalCoordinates(m_board, curr_player, validCoordinates);
    if (validCoordinates.empty()) // checking if the other player has any legal moves
    { // there is no options for either of the players
        m_boardGraphic.printSpecialSituation(NoMovesForAll);
        noMovesForAll = true;
    } else {


        //no possible moves for one player

        ///no possible moves for one player/


        curr_player->sendNoMove();
        curr_player->setNeedToSendMove(false);
        switchPlayer();
        if (noMove && inputCoordinate.row >0) {
            curr_player->sendMove(inputCoordinate);
            noMove = false;
        }
        //print No Moves situation in the Graphic tool.
        curr_player->printNoMoves(m_boardGraphic);
    }
    needToPrint = false;
}

void Game:: switchPlayer(){
    if (curr_player == players[turn]){
        curr_player = players[!turn];
    }else{
        curr_player = players[turn];
    }
}