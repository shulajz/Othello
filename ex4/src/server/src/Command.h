//
// Created by shulamit on 21/12/17.
////

#ifndef OTHELLO_COMMAND_H
#define OTHELLO_COMMAND_H

#include <vector>
#include <string>
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

class ClientData;
class Command {
public:
    Command(vector<Game*>& listOfGames):listOfGames(listOfGames){}
    virtual bool execute(string args, ClientData* data) = 0;
    virtual ~Command(){}

protected:
    vector <Game*>& listOfGames;


};
//

#endif //OTHELLO_COMMAND_H
