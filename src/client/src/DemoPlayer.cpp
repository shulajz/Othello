//
// Created by or on 12/5/17.
//

#include "DemoPlayer.h"

DemoPlayer:: DemoPlayer(TokenValue tv, ReversiClient* client) {
    this->tv = client->getOppositeTv();
    this->client = client;
}
void DemoPlayer::doOneTurn(GameRules *gameRules, Board &board,
                       vector<Coordinate> &coordinates,
                       Coordinate &input, BoardGraphic *boardGraphic, Player *player){
    input.row = client->receiveMove().row;
    input.col = client->receiveMove().col;
}
