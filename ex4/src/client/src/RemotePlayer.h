//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REMOTEPLAYER_H
#define OTHELLO_REMOTEPLAYER_H

#include "Player.h"
#include "ReversiClient.h"
#include "Menu.h"


class RemotePlayer: public Player {
public:
    RemotePlayer(TokenValue tv, Menu* subMenu);
    virtual void doOneTurn(GameRules *gameRules, Board &board,
                           vector<Coordinate> &coordinates,
                           Coordinate &input,
                           BoardGraphic *boardGraphic,
                           Player *player);
    void printWhatThePlayerPlayed(Coordinate coordinate,
                                  BoardGraphic *boardGraphic);
    void sendEndOfGame(Coordinate coordinate);
    void sendNoMove();
    void sendMove(Coordinate coordinate);
    void printNoMoves(BoardGraphic&  m_boardGraphic);
    ~RemotePlayer();

private:
    void subMenuForTheRemotePlayer(Menu* subMenu);
    ReversiClient* client;
};

#endif //OTHELLO_REMOTEPLAYER_H

