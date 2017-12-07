/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/

#include "Menu.h"
#include "RemotePlayer.h"
//#include "DemoPlayer.h"

Menu::~Menu(){};
Menu::Menu(){};
Player* Menu:: choosePlayer() const{
    Player* p;
    while (true) {
        char selection = getSelection();
        //H for Human Player
        if (selection == 'H') {
            p = new RealPlayer (White);
            return  p;
            //A for AIPlayer
        } else if (selection == 'A') {
            p = new AIPlayer(White);
            return p;
        }else if(selection == 'R'){
            return NULL;
        } else {
            //illegal option
            printWrongChoice();
        }
    }
}
