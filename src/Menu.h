/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:
*/
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
