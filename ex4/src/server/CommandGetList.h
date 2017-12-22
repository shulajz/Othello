//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDGETLIST_H
#define OTHELLO_COMMANDGETLIST_H

#include "Command.h"
#include "../client/src/Tools.h"

class CommandGetList: public Command {
public:
    CommandGetList(vector<Game>& listOfGames, int socket);
    virtual void execute(vector<string> args);
private:
    vector<Game> &m_listOfGames;
    int socket;
};


#endif //OTHELLO_COMMANDGETLIST_H
