//
// Created by shulamit on 21/12/17.
////

#ifndef OTHELLO_COMMANDCLOSE_H
#define OTHELLO_COMMANDCLOSE_H

#include "Command.h"
#include "CommandsManager.h"

class CommandClose: public Command {
public:
    CommandClose(vector <Game*> &listOfGames);
    virtual bool execute(string args, ClientData* data);
};


#endif //OTHELLO_COMMANDCLOSE_H
//