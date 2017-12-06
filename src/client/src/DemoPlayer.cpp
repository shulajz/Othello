//
// Created by or on 12/5/17.
//

#include <cstdlib>
#include "DemoPlayer.h"


using namespace std;

DemoPlayer:: DemoPlayer(TokenValue tv, ReversiClient* client) {
    this->tv = client->getOppositeTv();
    this->client = client;
}
void DemoPlayer::doOneTurn(GameRules *gameRules, Board &board,
                       vector<Coordinate> &coordinates,
                           Coordinate &input, BoardGraphic *boardGraphic, Player *player){
    bool inputValid = false;
    do {

        string coordinate = client->receiveMove();
        cout<<"DemoPlayerMove:"<<coordinate;
        int pos = coordinate.find_first_of(',');
        input.row = atoi(coordinate.substr(pos + 1).c_str());
        input.col = atoi(coordinate.substr(0, pos).c_str());
        for (int i = 0; i < coordinates.size(); i++) {
            //checks if the input is one of the legal coordinates
            if (input.row == coordinates[i].row && input.col == coordinates[i].col) {
                inputValid = true;
                break;
            }
        }
    }while(!inputValid);
}

bool DemoPlayer::isDemoPlayer() {
    return true;
}


ReversiClient* DemoPlayer :: getClient()const{
    return client;
}

