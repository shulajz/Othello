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
    virtual void printOptionsMenu() const = 0;
    Player* choosePlayer()const;
    ~Menu();
protected:
    virtual char getSelection() const = 0;
    virtual void printWrongChoice()const = 0;

};

#endif //OTHELLO_MENU_H
