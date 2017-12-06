//
// Created by or on 12/4/17.
//

#include "RemotePlayer.h"
#include "ReversiClient.h"
#include "GameRules.h"
#include <iostream>
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

bool RemotePlayer :: isMyTurn() {
    return client->isMyTurn();
}



void RemotePlayer::doOneTurn(GameRules *gameRules, Board &board,
                             vector<Coordinate> &coordinates,
                             Coordinate &input, BoardGraphic *boardGraphic, Player *player){
    bool inputValid = false;
    boardGraphic->printWhosMove(player->getIdentity());
    boardGraphic->printMoves(coordinates);
    boardGraphic->printSpecialSituation(AskForRowAndCol);
    while (!inputValid) {
        char temp;
        string string;
        cin>>string;
        //cin >> input.row>>temp >> input.col;
        cout << "Sending Move: " <<string;
        //cout << "Sending Move: " << input.row << ", "<<input.col << endl;
//        for (int i = 0; i < coordinates.size(); i++) {
//            //checks if the input is one of the legal coordinates
//            if (input.row == coordinates[i].row && input.col == coordinates[i].col) {
//                inputValid = true;
//                break;
//            }
//        }
//        if (inputValid) {
//            try {
        Coordinate coor = client->sendMove(string);

        //Coordinate coor = client->sendMove(input.row, input.col);
                cout << "row input: " << coor.row <<endl<<"col input: "<< coor.col<< endl;
//            } catch (const char *msg) {
//                cout << "Failed to send exercise to server. Reason: " << msg << endl;
//            }
//            break;
        //} else {
          //  boardGraphic->printSpecialSituation(IllegelMove);
      //  }
    }
}

bool RemotePlayer:: isRemotePlayer()const{
    return true;
}



