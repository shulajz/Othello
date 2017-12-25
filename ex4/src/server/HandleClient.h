//
// Created by or on 12/25/17.
//

#ifndef OTHELLO_HANDLECLIENT_H
#define OTHELLO_HANDLECLIENT_H
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include "CommandsManager.h"

using namespace std;

class HandleClient {
public:
    HandleClient();
    void run(int clientSocket);
    void handleClient(void* element);
    static void* gateFunction(void* element);
    void readCommand(int clientSocket, string &command, string &args);
private:
    pthread_mutex_t handle_client_locker;
    pthread_mutex_t connect_client_locker;
    int num_of_clients;
    vector<pthread_t> threads;
    CommandsManager commandsManager;
    vector<Game*> listOfGames;

};

struct ClientData {
    int clientSocket;
    HandleClient* server;

};


#endif //OTHELLO_HANDLECLIENT_H
