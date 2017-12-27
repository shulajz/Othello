//
// Created by shulamit on 21/12/17.

//
#ifndef OTHELLO_COMMANDSMANAGER_H
#define OTHELLO_COMMANDSMANAGER_H

#include <map>
#include "Command.h"

using namespace std;

class ClientData;
class Command;
class Game;

class CommandsManager {
public:
    CommandsManager(vector<Game*> &listOfGames);
    ~CommandsManager();

    bool executeCommand(string command, string args, ClientData* clientData);
private:
    map<string, Command *> commandsMap;
};


#endif //OTHELLO_COMMANDSMANAGER_H
