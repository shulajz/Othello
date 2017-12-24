//
// Created by shulamit on 21/12/17.
//
#include <iostream>
#include "CommandsManager.h"
#include "CommandJoin.h"
#include "ReversiServer.h"

void CommandJoin::execute(string args, ClientData* data){
    data->server->join(args, data->clientSocket);
}
