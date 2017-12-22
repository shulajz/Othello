//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMAND_H
#define OTHELLO_COMMAND_H

#include <vector>
#include <string>
using namespace std;

class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};


#endif //OTHELLO_COMMAND_H
