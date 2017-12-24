//
// Created by shulamit on 21/12/17.
//

#include <unistd.h>
#include <iostream>
#include "CommandStart.h"
#include "ReversiServer.h"
void CommandStart::execute(string args, ClientData* data){
    data->server->startCommand(args, data->clientSocket);
}