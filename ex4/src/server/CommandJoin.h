//
// Created by shulamit on 21/12/17.
////

#ifndef OTHELLO_COMMANDJOIN_H
#define OTHELLO_COMMANDJOIN_H

#include "Command.h"

//#include "../client/src/Tools.h"

class CommandJoin: public Command {
public:
    CommandJoin(vector<Game *> &listOfGames, CommandsManager* commandsManager);
    virtual bool execute(string args, ClientData* data);

private:
    CommandsManager* commandsManager;
//    vector <Game*> listOfGames;
};


#endif //OTHELLO_COMMANDJOIN_H
