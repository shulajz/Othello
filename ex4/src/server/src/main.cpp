//
// Created by or on 12/4/17.
///
//
#include "ReversiServer.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {
    HandleClientReversi handleClientReversi;
    string port;
    ifstream myFile;
    myFile.open("portOnly");
    if (myFile.is_open()) {
        myFile >> port;
        ReversiServer server(atoi(port.c_str()), handleClientReversi);
        try {
            server.start();
        } catch (const char *msg) {
            cout << "Cannot start server. Reason: " << msg << endl;
            exit(-1);
        }
    }
}