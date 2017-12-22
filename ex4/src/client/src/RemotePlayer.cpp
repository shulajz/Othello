//
// Created by or on 12/4/17.
//

#include "RemotePlayer.h"
#include <cstdlib>
#include <fstream>

using namespace std;

RemotePlayer::RemotePlayer(Menu* subMenu){
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
            subMenuForTheRemotePlayer(subMenu);
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
    boardGraphic->printSpecialSituation(WaitToMove);
    if (input.row) {
        //this is not the first move (input is not zero)
        client->sendMove(input);
    }
    input = client->receiveMove();
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

void RemotePlayer:: subMenuForTheRemotePlayer(Menu* subMenu){
    string command;
    do {
        command = subMenu->getChoose();
        //client->sendCommand(command, subMenu);

    }while (command == "list_games");
    subMenu->printSpecialSituation(WaitToJoin);
}