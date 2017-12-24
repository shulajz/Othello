//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDPLAY_H
#define OTHELLO_COMMANDPLAY_H


#include <vector>
//#include "../client/src/Tools.h"
#include "Command.h"
//#include "ReversiServer.h"

class CommandPlay: public Command {

public:
    virtual void execute(string args, ClientData* data);
};


#endif //OTHELLO_COMMANDPLAY_H
