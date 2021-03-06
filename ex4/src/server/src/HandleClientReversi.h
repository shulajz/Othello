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
#include "HandleClient.h"

using namespace std;

class HandleClientReversi : public HandleClient{
public:
    HandleClientReversi();
    void sendCloseToEveryOne(); //vir
    void run(int clientSocket); //vir
    void handleCommands(void* element);
    static void* gateFunction(void* element);
    void readCommand(int clientSocket, string &command, string &args);
    void pushThread(pthread_t thread);
    void eraseThread(pthread_t thread);
    HandleClient* getHandleClient();
private:
    pthread_mutex_t handle_client_locker;
    vector<pthread_t> threads;
    vector <Game*> listOfGames;
    CommandsManager commandsManager;
};

struct ClientData {
    int clientSocket;
    HandleClientReversi* handleClient;
};
#endif //OTHELLO_HANDLECLIENT_H