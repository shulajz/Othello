//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDCLOSE_H
#define OTHELLO_COMMANDCLOSE_H

#include "Command.h"
#include "CommandsManager.h"
//#include "../client/src/Tools.h"
//#include "ReversiServer.h"

class CommandClose: public Command {
public:
    CommandClose(vector <Game*> &listOfGames);
    virtual bool execute(string args, ClientData* data);

private:
//    vector <Game*> listOfGames;
};


#endif //OTHELLO_COMMANDCLOSE_H
