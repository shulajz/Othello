//
// Created by or on 11/20/17.
//

#ifndef OTHELLO_CONSOLEMENU_H
#define OTHELLO_CONSOLEMENU_H

#include "Menu.h"
class ConsoleMenu: public Menu {
    virtual void printWrongChose()const;
    virtual void printOptionsMenu() const;
    virtual char getSelection() const;
};

#endif //OTHELLO_CONSOLEMENU_H
