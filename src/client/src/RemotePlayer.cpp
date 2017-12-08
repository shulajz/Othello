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
        this->tv = client->getTokenValueOfPlayer();
    }while(this->tv != Black && this->tv != White);


}

void RemotePlayer::doOneTurn(GameRules *gameRules, Board &board,
                             vector<Coordinate> &coordinates,
                             Coordinate &input, BoardGraphic *boardGraphic, Player *player){
        boardGraphic->printSpecialSituation(Wait);
        if (input.row) {
            //this is not the first move
            client->sendMove(input);
        }
        input = client->receiveMove();
        cout << input.row<<" ,"<< input.col << endl;
        if (input.row == End){
            client->sendEnd();
        }

}

void RemotePlayer:: printWhatThePlayerPlayed(Coordinate coordinate,
                                          BoardGraphic *boardGraphic) {
    boardGraphic->printThePlayersChoice(tv, coordinate);
}

void RemotePlayer::sendEndOfGame(Coordinate coordinate){
    client->sendMove(coordinate);
    client->sendEnd();
}