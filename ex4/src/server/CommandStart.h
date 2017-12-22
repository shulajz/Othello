//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_STARTCOMMAND_H
#define OTHELLO_STARTCOMMAND_H


#include "Command.h"
#include "../client/src/Tools.h"

class CommandStart: public Command {
public:
    CommandStart(vector<Game>& listOfGames, int socket);
    virtual void execute(vector<string> args);
private:
    vector<Game> &m_listOfGames;
    int socket;
};


#endif //OTHELLO_STARTCOMMAND_H
