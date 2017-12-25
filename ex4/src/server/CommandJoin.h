//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDJOIN_H
#define OTHELLO_COMMANDJOIN_H

#include "Command.h"

//#include "../client/src/Tools.h"

class CommandJoin: public Command {
public:
    CommandJoin(vector<Game *> &listOfGames);
    virtual bool execute(string args, ClientData* data);
    void sendValueOfClient(int clientSocket1, int clientSocket2);

private:
//    vector <Game*> listOfGames;
};


#endif //OTHELLO_COMMANDJOIN_H
