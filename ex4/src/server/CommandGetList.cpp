//
// Created by shulamit on 21/12/17.
//

#include <unistd.h>
#include <iostream>
#include "CommandGetList.h"
#include "ReversiServer.h"
//
using namespace std;

void CommandGetList::execute(string args, ClientData* data){
    data->server->listGames(data->clientSocket);
}