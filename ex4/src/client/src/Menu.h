/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/
#ifndef OTHELLO_MENU_H
#define OTHELLO_MENU_H

#include <iostream>
#include "Player.h"

enum TypeMenu{
    MainMenu, SubMenu
};


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
    virtual void printOptionsMenu(TypeMenu typeMenu) const = 0;

    /**
     * This function handles the choice of the real player against who he want to play.
     * @return the type of the player the real player wants to play
     */
    void getChoose(Player* players[2]);

    /**
     * This function handles the choice of the real player against who he want to play.
     * @return the type of the player the real player wants to play
     */
    string getChoose();
    /**
     * deconstructor of Menu.
     */////
    ~Menu();

    virtual void printSpecialSituation(Situation message) const = 0;

    virtual void printList(string listOfAvailableGames) const = 0;

    /**
     *This function print in case of wrong selection (that not exist in the menu) .
     */
    virtual void printWrongChoice()const = 0;

    virtual void printWhoPlay(TokenValue tv)const =0;

    virtual void printServerClosed()const = 0;

protected:

    /**
     * This function receives the selection of the player.
     * @return the key(char) of the option in the menu the real player choose
     */
    virtual string getSelection() const = 0;

    void chooseRealPlayer(Player* players[]);

    void chooseAiPlayer(Player* players[]);

    void chooseRemotePlayer(Player* players[]);


};

#endif //OTHELLO_MENU_H
//