/*
 * ex3.c
 *
 *  Created on:
 *  Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/
//
#include "Menu.h"
#include "RemotePlayer.h"
#include "RealPlayer.h"
#include "AIPlayer.h"
#include "ConsoleToken.h"

using namespace std;

Menu::~Menu(){};
Menu::Menu(){};


void Menu:: getChoose(Player* players[2]){
    printOptionsMenu(MainMenu);
    while (true) {
        string selection = getSelection();
        //H for Human Player
        if (selection == "H") {
            chooseRealPlayer(players);
            return;
            //A for AIPlayer
        } else if (selection == "A") {
            chooseAiPlayer(players);
            return;
            //R for RemotePlayer
        }else if(selection == "R"){
            chooseRemotePlayer(players);
            return;
        } else {
            //illegal option
            printWrongChoice();
        }
    }
}


string Menu:: getChoose(){
    printOptionsMenu(SubMenu);
    while (true) {
        string selection = getSelection();
        if (selection.substr(0,5) == "start"
            ||
                selection.substr(0,4) == "join"
            ||
                selection.substr(0,10) == "list_games"){
            return selection;
        } else {
            //illegal option
            printWrongChoice();
        }
    }
}


void Menu::chooseRealPlayer(Player* players[2]){
    Player* p2;
    Player* p1;
    p2 = new RealPlayer (White);
    p1 = new RealPlayer (Black);
    players[Black] = p1;
    players[White] = p2;
}

void Menu::chooseAiPlayer(Player* players[2]){
    Player* p2;
    Player* p1;
    p2 = new AIPlayer(White);
    p1 = new RealPlayer (Black);
    players[Black] = p1;
    players[White] = p2;

}
//

void Menu::chooseRemotePlayer(Player* players[2]){
    Player* p2;
    Player* p1;
    Player *remotePlayer = new RemotePlayer(this);
    if(remotePlayer->getValue() == Black) {
        //if this is the first client
        p1 = new RealPlayer(Black);
        p2 = remotePlayer;
        remotePlayer->setTokenValue(White);
    } else {
        //this is the second client
        p1 = remotePlayer;
        remotePlayer->setTokenValue(Black);
        p2 = new RealPlayer(White);
    }
    players[Black] = p1;
    players[White] = p2;

}

