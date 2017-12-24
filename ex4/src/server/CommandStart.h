//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_STARTCOMMAND_H
#define OTHELLO_STARTCOMMAND_H


#include "Command.h"
//#include "../client/src/Tools.h"
//#include "ReversiServer.h"

class CommandStart: public Command {
public:
    virtual void  execute(string args, ClientData* data);
};


#endif //OTHELLO_STARTCOMMAND_H
