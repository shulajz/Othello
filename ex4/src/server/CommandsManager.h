//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDSMANAGER_H
#define OTHELLO_COMMANDSMANAGER_H

#include <map>
#include "Command.h"
#include "ReversiServer.h"

class CommandsManager {
public:
    CommandsManager(vector<Game> &listOfGames, int socket);
    ~CommandsManager();

    void executeCommand(string command,
                        vector<string> args);
private:

    map<string, Command *> commandsMap;
    vector<Game> listOfGames;
    int socket;
};


#endif //OTHELLO_COMMANDSMANAGER_H
