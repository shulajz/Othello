//
// Created by shulamit on 21/12/17.
//

#include "CommandPlay.h"
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "ReversiServer.h"
using namespace std;


void CommandPlay::execute(string args, ClientData* data){
    cout << "args in commandPlay:" << args<< endl;
    int row, col;
    string buf; // Have a buffer string
    stringstream ss(args); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    row = atoi(tokens[0].c_str());
    col = atoi(tokens[1].c_str());
    cout<<"command row: "<<row
        << endl << "command col: "<< col<<endl;
    data->server->play(row, col, data->clientSocket);
}