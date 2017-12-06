//
// Created by or on 12/5/17.
//

#ifndef OTHELLO_DEMOPLAYER_H
#define OTHELLO_DEMOPLAYER_H


#include "Player.h"
#include "ReversiClient.h"

class DemoPlayer: public Player {
public:
    DemoPlayer(TokenValue,ReversiClient*);
    virtual void doOneTurn(GameRules *gameRules, Board &board,
                           vector<Coordinate> &coordinates,
                           Coordinate &input, BoardGraphic *boardGraphic, Player *player);
    bool isDemoPlayer();
    ReversiClient* getClient() const;
private:
    ReversiClient* client;
    
};


#endif //OTHELLO_DEMOPLAYER_H
