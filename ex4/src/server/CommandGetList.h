//
// Created by shulamit on 21/12/17.
////

#ifndef OTHELLO_COMMANDGETLIST_H
#define OTHELLO_COMMANDGETLIST_H

#include "Command.h"
#include "CommandsManager.h"


class CommandGetList: public Command {
public:
    CommandGetList(vector<Game *> &listOfGames);
    virtual bool execute(string args, ClientData* data);
};


#endif //OTHELLO_COMMANDGETLIST_H
