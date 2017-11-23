//
// Created by or on 11/20/17.
//

#include "Menu.h"

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
            p = new AIPlayer (White);
            return p;
        } else {
            //illegal option
            printWrongChoice();
        }
    }
}

