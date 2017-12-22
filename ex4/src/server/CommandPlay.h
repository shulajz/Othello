//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDPLAY_H
#define OTHELLO_COMMANDPLAY_H


#include <vector>
#include "../client/src/Tools.h"
#include "Command.h"

class CommandPlay: public Command {

public:
    CommandPlay(vector<Game>& listOfGames, int socket);
    virtual void execute(vector<string> args);
private:
    vector<Game> &m_listOfGames;
    int socket;
};


#endif //OTHELLO_COMMANDPLAY_H
