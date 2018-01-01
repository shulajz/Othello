//
// Created by or on 12/4/17.
//

#include "RemotePlayer.h"
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

RemotePlayer::RemotePlayer(Menu* subMenu): subMenu(subMenu){
    string ip;
    string port;
    ifstream myFile;
    myFile.open("ipAndPort");
    if (myFile.is_open()) {
        myFile >> ip;
        myFile >> port;
        char *ipBuff = new char[ip.length() + 1];
        strcpy(ipBuff, ip.c_str());
        client = new ReversiClient(ipBuff, atoi(port.c_str()), subMenu);
        try {
            subMenuForTheRemotePlayer();
        } catch (const char *msg) {
            cout << "Failed to connect to server. Reason:" << msg << endl;
        }
        do {
            this->tv = client->getTokenValueOfPlayer();
        } while (this->tv != Black && this->tv != White);
        subMenu->printWhoPlay(this->tv);
        delete(ipBuff);
    }
}

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

void RemotePlayer::printNoMoves(BoardGraphic&  m_boardGraphic){
    m_boardGraphic.printSpecialSituation(NoMoveForTheRival);
}

RemotePlayer::~RemotePlayer(){
    delete(client);
}

void RemotePlayer:: subMenuForTheRemotePlayer(){
    string command;
    int valid;
    bool isListGames = false;
    do {
        command = subMenu->getChoose();
        client->connectToServer();
        client->sendCommand(command, isListGames, valid);
        if(!isListGames) {//if its a list we killed the socket so we don't want to read anymore
            valid = client->getValid();
            //if this is a badInput and the command is not to print list of available games
            //then update the client that he do a wrong choose and he need to try again.
            if(valid == BadInput){
                subMenu->printWrongChoice();
            }
        }
    }while (valid == BadInput);
    subMenu->printSpecialSituation(WaitToJoin);
}