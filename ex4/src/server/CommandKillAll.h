//
// Created by or on 12/26/17.
//

#ifndef OTHELLO_COMMANDKILLALL_H
#define OTHELLO_COMMANDKILLALL_H

enum StatusOfGame{
    Close = -4,
};
#include "Command.h"

class CommandKillAll: public Command {
public:
    CommandKillAll(vector <Game*> &listOfGames);
    virtual bool execute(string args, ClientData* data);
};


#endif //OTHELLO_COMMANDKILLALL_H
