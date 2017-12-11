//
// Created by or on 12/4/17.
//

#include "RemotePlayer.h"
#include "ReversiClient.h"
#include "GameRules.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

RemotePlayer::RemotePlayer(TokenValue tv): needToPrint(true), printOnlyOneTime(true), needToSendMove(true) {
    string ip;
    string port;
    ifstream myFile;
    myFile.open("ipAndPort");
    if (myFile.is_open()) {
        myFile >> ip;
        myFile >> port;
        char *ipBuff = new char[ip.length() + 1];
        strcpy(ipBuff, ip.c_str());
        client = new ReversiClient(ipBuff, atoi(port.c_str()));
        try {
            client->connectToServer();
        } catch (const char *msg) {
            cout << "Failed to connect to server. Reason:" << msg << endl;
        }
        do {
            this->tv = client->getTokenValueOfPlayer();
        } while (this->tv != Black && this->tv != White);
        delete(ipBuff);
    }

}
//
void RemotePlayer::doOneTurn(GameRules *gameRules, Board &board,
                             vector<Coordinate> &coordinates,
                             Coordinate &input, BoardGraphic *boardGraphic, Player *player){
    //if is remote player turn print to the real player he need
    // to wait to the other player to do is ove
    if (needToPrint) {
        boardGraphic->printSpecialSituation(WaitToMove);
    }
    needToPrint = true;
    if (input.row && needToPrint && needToSendMove) {
        //this is not the first move
        client->sendMove(input);
    }
    input = client->receiveMove();
    //if the input present NoMove situation
    if (input.row == NoMove){
       //if there is no move the player need to stay remote player and not to change
        // his turn to the real player, so we don't want in his next time
        // the remote will do is turn will print WaitToMove or send move.
        needToPrint = false;
    }
    //if the current input is End we will send End
    if (input.row == End){
        client->sendEnd();
    }
    needToSendMove = true;
}

void RemotePlayer:: printWhatThePlayerPlayed(Coordinate coordinate,
                                          BoardGraphic *boardGraphic) {
    boardGraphic->printThePlayersChoice(tv, coordinate);
}

void RemotePlayer::sendEndOfGame(Coordinate coordinate){
    if (coordinate.row > 0) {
        client->sendMove(coordinate);
    }
    client->sendEnd();
}
void RemotePlayer::sendNoMove(){
    client->sendNoMove();
}

void RemotePlayer::sendMove(Coordinate coordinate){
    client->sendMove(coordinate);
}

void RemotePlayer::printNoMoves(BoardGraphic&  m_boardGraphic){
    m_boardGraphic.printSpecialSituation(NoMoveForTheRival);
}

RemotePlayer::~RemotePlayer(){
    delete(client);
}

void RemotePlayer:: setNeedToSendMove(bool boolean){
    needToSendMove = boolean;
}