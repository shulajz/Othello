//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDGETLIST_H
#define OTHELLO_COMMANDGETLIST_H

#include "Command.h"
//#include "../client/src/Tools.h"
//#include "ReversiServer.h"

class CommandGetList: public Command {
public:
    virtual void execute(string args, ClientData* data);
};


#endif //OTHELLO_COMMANDGETLIST_H
