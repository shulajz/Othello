//
// Created by shulamit on 10/31/17.
//

#include "GameFlow.h"



using namespace std;

GameFlow ::GameFlow(GameRules &gameRules, Player **players, Board &board, BoardGraphic &boardGraphic):
        m_gameRules(gameRules),m_board(board), m_boardGraphic(boardGraphic),first_move(true) {
    this->players = players;
    turn = Black;
    curr_player = players[Black];

}

//void GameFlow :: run()
/**
 * where the game runs...
 */
void GameFlow :: run () {
    bool endGame = false;
    Coordinate inputCoordinate;
    inputCoordinate.row = 0;
    inputCoordinate.col = 0;
    bool needToPrint=true;
    while (true) {
        if (!printBoardIfNeed(needToPrint, inputCoordinate)) {//return false if the board full
            //if first move and the board full
            if (first_move) {
                players[!curr_player->getValue()]->sendEndOfGame(inputCoordinate);
            }
            curr_player->sendEndOfGame(inputCoordinate);
            break; // the board is full of tokens - end game
        }
        if (!first_move && (needToPrint)) {
            if (inputCoordinate.row != NoMove) {
                players[!curr_player->getValue()]->printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
            }
        }
        first_move = false;
        vector<Coordinate> validCoordinates;
        m_gameRules.getLegalCoordinates(m_board, curr_player, validCoordinates);

        if (validCoordinates.empty()) {
            ifNoValidCoordinates(validCoordinates, needToPrint, endGame,  inputCoordinate);
            if (endGame) { //there is no options for either of the players - end game
                break;
            }
        } else {
            ifValidCoordinates(validCoordinates, needToPrint, inputCoordinate);
        }
        switchPlayer();
    }
    //func of print status
    int black = 0;
    int white = 0;
    m_board.calcResults(black, white);
    m_boardGraphic.drawStatus(black, white);
}

bool GameFlow::printBoardIfNeed(bool &needToPrint, Coordinate& inputCoordinate){
    //if the board full print and break.
    if (m_board.isFullOfTokens()) {
        m_board.draw();
        if (!first_move && (needToPrint)) {
            players[!curr_player->getValue()]->printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
            curr_player->printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);
        }
        needToPrint = false;
        return false;
    }
    if ((needToPrint||curr_player->isRealPlayer())) {
        m_board.draw();
    }
    return true;
}

void GameFlow::ifNoValidCoordinates(vector<Coordinate>& validCoordinates,
                                    bool& needToPrint, bool &endGame, Coordinate& inputCoordinate){
    //switching to the other player in order to check
    // if he's got any legal moves
    switchPlayer();
    m_gameRules.getLegalCoordinates(m_board, curr_player,validCoordinates);
    if (validCoordinates.empty()) // checking if the other player has any legal moves
    { // there is no options for either of the players
        m_boardGraphic.printSpecialSituation(NoMovesForAll);
        curr_player->sendEndOfGame(inputCoordinate);
        players[!curr_player->getValue()]->sendEndOfGame(inputCoordinate);
        endGame = true;
    } else {
        //no possible moves for one player
        curr_player->sendNoMove();

        switchPlayer();
        m_boardGraphic.printWhosMove(curr_player->getValue());
        m_boardGraphic.printSpecialSituation(Next);
        needToPrint = false;
    }
}

void GameFlow::ifValidCoordinates(vector<Coordinate>& validCoordinates, bool& needToPrint,
                                  Coordinate& inputCoordinate){

    curr_player->printAfterTheRealPlayerMove(&m_boardGraphic,needToPrint);
    curr_player->doOneTurn(&m_gameRules, m_board, validCoordinates, inputCoordinate, &m_boardGraphic, curr_player);
    //check if there is valid coordinates if so, update the value of the inputCoordinate in the board
    //and flip tokens.
    if(inputCoordinate.row > 0 && inputCoordinate.col>0){
        m_board.updateValue(inputCoordinate, curr_player->getValue());
        m_gameRules.flipTokens(inputCoordinate, m_board, curr_player);
    }
    needToPrint = true;
    if (inputCoordinate.row == NoMove && inputCoordinate.col == NoMove){
        switchPlayer();
        needToPrint = false;
    }
}

void GameFlow :: switchPlayer(){
    if (curr_player == players[turn]){
        curr_player = players[!turn];
    }else{
        curr_player = players[turn];
    }
}