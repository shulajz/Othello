//
// Created by shulamit on 21/12/17.
////

#ifndef OTHELLO_COMMANDJOIN_H
#define OTHELLO_COMMANDJOIN_H

#include "Command.h"



class CommandJoin: public Command {
public:
    CommandJoin(vector<Game *> &listOfGames, CommandsManager* commandsManager);
    virtual bool execute(string args, ClientData* data);

private:
    CommandsManager* commandsManager;
};


#endif //OTHELLO_COMMANDJOIN_H
//