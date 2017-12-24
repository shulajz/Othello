//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDJOIN_H
#define OTHELLO_COMMANDJOIN_H

#include "Command.h"

//#include "../client/src/Tools.h"

class CommandJoin: public Command {
public:
    virtual void execute(string args, ClientData* data);
};


#endif //OTHELLO_COMMANDJOIN_H
