//
// Created by or on 11/20/17.
//

#ifndef OTHELLO_CONSOLEMENU_H
#define OTHELLO_CONSOLEMENU_H

#include "Menu.h"
class ConsoleMenu: public Menu {
public:

   /**
    *This function print message on the console, in case of wrong select (that not exist in the menu) .
    */
    virtual void printWrongChoice()const;

   /**
    * Print the options of the menu in the console.
    */
    virtual void printOptionsMenu(TypeMenu typeMenu) const;

    /**
     * This function get the selection of the player by use the console
     * @return the key(char) of the option in the menu the real player choose
     */
    virtual string getSelection() const;

    virtual void printSpecialSituation(Situation message) const;

    virtual void printList(string listOfAvailableGames) const;
};

#endif //OTHELLO_CONSOLEMENU_H
