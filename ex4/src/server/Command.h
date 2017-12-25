//
// Created by shulamit on 21/12/17.
//

#ifndef OTHELLO_COMMAND_H
#define OTHELLO_COMMAND_H

#include <vector>
#include <string>
#include "CommandsManager.h"
using namespace std;

enum StatusOfClientInGame {
    Active, Waiting
};

struct Game {
    string name;
    int socket1;
    int socket2;
    StatusOfClientInGame status;
};
#include "ReversiServer.h"
class ClientData;
class Command {
public:
    Command(vector<Game*>& listOfGames):listOfGames(listOfGames){}
    virtual bool execute(string args, ClientData* data) = 0;
    virtual ~Command(){}
    virtual void Print(){cout << "Generic Command" << endl;}

protected:
    vector <Game*>& listOfGames;


};


#endif //OTHELLO_COMMAND_H
