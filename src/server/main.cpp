//
// Created by or on 12/4/17.
//

#include "ReversiServer.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
 ReversiServer server(8000);
 try {
    server.start();
 } catch (const char *msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
 }
}