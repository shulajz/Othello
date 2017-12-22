//
// Created by shulamit on 21/12/17.
//


#include "CommandsManager.h"
#include "Command.h"
#include "CommandStart.h"

CommandsManager::CommandsManager(vector<Game> &listOfGames, int socket):
        socket(socket), listOfGames(listOfGames) {
    commandsMap["start"] = new StartCommand(listOfGames, socket);
    // Add more commands...
}
void CommandsManager::executeCommand(string
                                     command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it !=
                                   commandsMap.end(); it++) {
        delete it->second;
    }
}