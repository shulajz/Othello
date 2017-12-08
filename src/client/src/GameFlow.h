//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_GAMEFLOW_H
#define OTHELLO_GAMEFLOW_H


#include "GameRules.h"
#include "Player.h"
#include "Board.h"

class GameFlow {
private:
    Player **players;
    GameRules &m_gameRules;
    Board &m_board;
    TokenValue currentTurn;
    BoardGraphic &m_boardGraphic;
    bool printBoardIfNeed(bool& needToPrint);
    void ifNoValidCoordinates(vector<Coordinate>& validCoordinates,
                              bool& needToPrint, bool &endGame, Coordinate& inputCoordinate);
    void ifValidCoordinates(vector<Coordinate>& validCoordinates, bool& needToPrint,
                            Coordinate& inputCoordinate);
public:
    GameFlow(GameRules &gameRules, Player **players, Board &board, BoardGraphic &boardGraphic);
    //the game flow//
    void run();
};


#endif //OTHELLO_GAMEFLOW_H
