//
// Created by or on 12/8/17.
//

#ifndef OTHELLO_GAME_H
#define OTHELLO_GAME_H


#include "GameRules.h"

class Game {
public:
    Game(GameRules &gameRules, Player **players, Board &board, BoardGraphic &boardGraphic);
    //the game flow
    void run();
private:

    Player **players;
    GameRules &m_gameRules;
    Board &m_board;
    TokenValue turn;
    BoardGraphic &m_boardGraphic;
    bool first_move;
    Player* curr_player;
    Coordinate inputCoordinate;
    bool needToPrint;
    bool noMovesForAll;
    void  printStatus();
    void playOneTurn();
    void ifNoValidCoordinates(vector<Coordinate>& validCoordinates);
    void ifValidCoordinates(vector<Coordinate>& validCoordinates);
    void switchPlayer();
};


#endif //OTHELLO_GAME_H
