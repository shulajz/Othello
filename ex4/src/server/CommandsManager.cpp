//
// Created by shulamit on 21/12/17.
//


#include "CommandsManager.h"
#include "CommandStart.h"
#include "CommandClose.h"
#include "CommandGetList.h"
#include "CommandJoin.h"
#include "CommandPlay.h"

CommandsManager::CommandsManager() {

    commandsMap["start"] = new CommandStart();
    commandsMap["close"] = new CommandClose();
    commandsMap["list_games"] = new CommandGetList();
    commandsMap["join"] = new CommandJoin();
    commandsMap["play"] = new CommandPlay();

}
void CommandsManager::executeCommand(string
                                     command, string args, ClientData* clientData) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args, clientData);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it !=
                                   commandsMap.end(); it++) {
        delete it->second;
    }
}