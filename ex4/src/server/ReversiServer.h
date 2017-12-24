//
// Created by or on 12/4/17.
//

#ifndef OTHELLO_REVERSISERVER_H
#define OTHELLO_REVERSISERVER_H
#include <string.h>
#include <iostream>
#include "vector"
#include "CommandsManager.h"


using namespace std;
//
enum StatusOfClientInGame {
    Active, Waiting
};

struct Game {
    string name;
    int socket1;
    int socket2;
    StatusOfClientInGame status;
};


//class CommandsManager;

//enum StatusForClient {
//    NoMove = -2, End = -3
//};

class ReversiServer {
public:
    ReversiServer(int port);
    void start();
    void stop();
    void join(string args, int clientSocket);
    void play(int row, int col, int clientSocket);
    void startCommand(string args, int clientSocket);
    void listGames(int clientSocket);
    void close(int clientSocket);

private:
    vector<Game*> listOfGames;
    vector<pthread_t> threads;
    bool receiveMove;
    bool endGame;
    int port;
    int serverSocket; // the socket's file descriptor;
    void handleClient(void* element);
    static void* gateFunction(void* element);
    CommandsManager commandsManager;
    void readCommand(int clientSocket, string &command, string &args);
    /**
     * send the value of the client in the start of the game
     * @param clientSocket1
     * @param clientSocket2
     */
    void sendValueOfClient(int clientSocket1, int clientSocket2);
    bool clientStoppedCloseAllClients;
//    pthread_mutex_t connection_locker;
    pthread_mutex_t handle_client_locker;
    pthread_mutex_t connect_client_locker;
    int num_of_clients;

};
struct ClientData {
    int clientSocket;
    ReversiServer* server;
};


#endif //OTHELLO_REVERSISERVER_H