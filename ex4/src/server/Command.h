//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMAND_H
#define OTHELLO_COMMAND_H

#include <vector>
#include <string>
//#include "ReversiServer.h"
using namespace std;
class ClientData;
class Command {
public:
    virtual void execute(string args, ClientData* data) = 0;
    virtual ~Command() {}
};


#endif //OTHELLO_COMMAND_H
