//
// Created by shulamit on 21/12/17.
//

#include "CommandClose.h"
#include "ReversiServer.h"

#include <unistd.h>
#include <iostream>
using namespace std;

void CommandClose::execute(string args,ClientData* data){
    data->server->close(data->clientSocket);
}