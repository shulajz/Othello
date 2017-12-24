//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMANDSMANAGER_H
#define OTHELLO_COMMANDSMANAGER_H

#include <map>
#include "Command.h"
//#include "ReversiServer.h"
//class Command;
class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();

    void executeCommand(string command, string args, ClientData* clientData);
private:

    map<string, Command *> commandsMap;
};


#endif //OTHELLO_COMMANDSMANAGER_H
