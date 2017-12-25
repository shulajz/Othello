//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_STARTCOMMAND_H
#define OTHELLO_STARTCOMMAND_H


#include "Command.h"
#include "CommandsManager.h"


class CommandStart: public Command {
public:
    CommandStart(vector<Game *> &listOfGames);
    virtual bool execute(string args, ClientData* data);
    void Print(){cout << "Start Command" << endl;}
private:
};


#endif //OTHELLO_STARTCOMMAND_H
