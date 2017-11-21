//
// Created by or on 11/20/17.
//

#ifndef OTHELLO_MENU_H
#define OTHELLO_MENU_H
#include <iostream>
#include "RealPlayer.h"
#include "AIPlayer.h"

class Menu {
public:
    Menu();
    void run();
    virtual void printOptionsMenu() const =0;
    Player* choosePlayer()const;
    virtual void printWrongChose()const=0;
    virtual char getSelection() const=0;
    ~Menu();

};

#endif //OTHELLO_MENU_H
