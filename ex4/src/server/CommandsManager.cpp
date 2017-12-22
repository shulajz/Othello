//
// Created by shulamit on 21/12/17.
//


#include "CommandsManager.h"
#include "Command.h"
#include "CommandStart.h"
#include "CommandClose.h"
#include "CommandGetList.h"
#include "CommandJoin.h"
#include "CommandPlay.h"

CommandsManager::CommandsManager(vector<Game> &listOfGames, int socket):
        socket(socket), listOfGames(listOfGames) {

    commandsMap["start"] = new CommandStart(listOfGames, socket);
    commandsMap["close"] = new CommandClose(listOfGames, socket);
    commandsMap["listGames"] = new CommandGetList(listOfGames, socket);
    commandsMap["join"] = new CommandJoin(listOfGames, socket);
    commandsMap["play"] = new CommandPlay(listOfGames, socket);

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