//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDCLOSE_H
#define OTHELLO_COMMANDCLOSE_H

#include "Command.h"
#include "../client/src/Tools.h"

class CommandClose {



public:
    CommandClose(vector<Game>& listOfGames, int socket);
    virtual void execute(vector<string> args);
private:
    vector<Game> &m_listOfGames;
    int socket;

};


#endif //OTHELLO_COMMANDCLOSE_H
