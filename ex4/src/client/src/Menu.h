/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/
#ifndef OTHELLO_MENU_H
#define OTHELLO_MENU_H
#include <iostream>
#include "RealPlayer.h"
#include "AIPlayer.h"

class Menu {
public:
    /**
     * Constructor of Menu.
     */
    Menu();
    /**
     * Run the menu.
     */
    void run();
    /**
     * Print the options of the menu
     */
    virtual void printOptionsMenu() const = 0;

    /**
     * This function handles the choice of the real player against who he want to play.
     * @return the type of the player the real player wants to play
     */
    Player* choosePlayer()const;
    /**
     * deconstructor of Menu.
     */
    ~Menu();
protected:

    /**
     * This function receives the selection of the player.
     * @return the key(char) of the option in the menu the real player choose
     */
    virtual char getSelection() const = 0;

    /**
     *This function print in case of wrong selection (that not exist in the menu) .
     */
    virtual void printWrongChoice()const = 0;


};

#endif //OTHELLO_MENU_H
