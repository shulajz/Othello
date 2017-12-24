//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDCLOSE_H
#define OTHELLO_COMMANDCLOSE_H

#include "Command.h"
//#include "../client/src/Tools.h"
//#include "ReversiServer.h"

class CommandClose: public Command {
public:
    virtual void execute(string args, ClientData* data);
};


#endif //OTHELLO_COMMANDCLOSE_H
