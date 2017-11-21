//
// Created by or on 11/20/17.
//

#include "Menu.h"

Menu::~Menu(){};
Menu::Menu(){};
Player* Menu:: choosePlayer() const{
    Player* p;

    while (true) {
        char selection =getSelection();
        if (selection== 'H') {
            p=new RealPlayer (White);
            return  p;
        }else if (selection== 'A') {
            p=new AIPlayer (White);
            return p;
        }else {
            printWrongChose();
        }
    }
}

