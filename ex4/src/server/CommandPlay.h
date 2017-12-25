//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDPLAY_H
#define OTHELLO_COMMANDPLAY_H


#include <vector>
#include "Command.h"
#include "CommandsManager.h"


class CommandPlay: public Command {

public:
    CommandPlay(vector<Game *> &listOfGames);
    virtual bool execute(string args, ClientData* data);
    void parseArgsToRowAndCol(string args, int& row, int& col);

private:
//    vector <Game*> listOfGames;
};


#endif //OTHELLO_COMMANDPLAY_H
