//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDJOIN_H
#define OTHELLO_COMMANDJOIN_H

#include "Command.h"

#include "../client/src/Tools.h"

class CommandJoin: public Command {
public:
    CommandJoin(vector<Game>& listOfGames, int socket);
    virtual void execute(vector<string> args);
    void sendValueOfClient(int clientSocket1, int clientSocket2);
private:
    vector<Game> &m_listOfGames;
    int socket;
};


#endif //OTHELLO_COMMANDJOIN_H
