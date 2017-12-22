//
// Created by or on 12/8/17.
//

#ifndef OTHELLO_GAME_H
#define OTHELLO_GAME_H


#include "GameRules.h"

class GameFlow {
public:
    GameFlow(GameRules &gameRules, Player **players, Board &board, BoardGraphic &boardGraphic);
    //the game flow
    void run();
private:

    Player **players;
    GameRules &m_gameRules;
    Board &m_board;
    TokenValue turn;
    BoardGraphic &m_boardGraphic;
    bool noMove;
    bool first_move;
    Player* curr_player;
    Coordinate inputCoordinate;
    bool needToPrint;
    bool thereIsAMoveForOnePlayer;
    void  printStatus();
    void playOneTurn();
    void handleOnePlayerHasAMove(vector<Coordinate>& validCoordinates);
    void switchPlayer();
    bool rivalHasAMove();
};


#endif //OTHELLO_GAME_H
