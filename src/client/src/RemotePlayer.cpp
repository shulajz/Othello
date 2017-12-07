//
// Created by or on 12/4/17.
//

#include "RemotePlayer.h"
#include "ReversiClient.h"
#include "GameRules.h"
#include <iostream>
#include <cstdlib>

using namespace std;

RemotePlayer::RemotePlayer(TokenValue tv):haveTwoPlayers(false){

    client= new ReversiClient("127.0.0.1", 8000);
    try {
        client->connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
    }
    do{
        this->tv=client->getTokenValueOfPlayer();
    }while(this->tv!=Black&&this->tv!=White);


}

ReversiClient* RemotePlayer :: getClient()const{
    return this->client;

}

//bool RemotePlayer :: isMyTurn() {
//    return client->isMyTurn();
//}



void RemotePlayer::doOneTurn(GameRules *gameRules, Board &board,
                             vector<Coordinate> &coordinates,
                             Coordinate &input, BoardGraphic *boardGraphic, Player *player){

    cout << "please wait for other player to do his move" << endl;

    if(input.row) {
        //this is not the first move
        client->sendMove(input);
    }
    input = client->receiveMove();

}

bool RemotePlayer:: isRemotePlayer()const{
    return true;
}


