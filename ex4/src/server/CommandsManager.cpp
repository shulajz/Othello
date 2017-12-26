//
// Created by shulamit on 21/12/17.
////


#include "CommandsManager.h"
#include "CommandStart.h"
#include "CommandClose.h"
#include "CommandGetList.h"
#include "CommandJoin.h"
#include "CommandPlay.h"

CommandsManager::CommandsManager(vector<Game*>& listOfGames) {

    commandsMap["start"] = new CommandStart(listOfGames);
    commandsMap["close"] = new CommandClose(listOfGames);
    commandsMap["list_games"] = new CommandGetList(listOfGames);
    commandsMap["join"] = new CommandJoin(listOfGames, this);
    commandsMap["play"] = new CommandPlay(listOfGames);

}

bool CommandsManager::executeCommand(string
                                     command, string args, ClientData* clientData) {
    Command *commandObj = commandsMap[command];
    return commandObj->execute(args, clientData);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it !=
                                   commandsMap.end(); it++) {
        delete it->second;
    }
}