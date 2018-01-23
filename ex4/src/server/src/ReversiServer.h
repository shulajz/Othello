//
// Created by or on 12/4/17.
//
//
#ifndef OTHELLO_REVERSISERVER_H
#define OTHELLO_REVERSISERVER_H
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "vector"
#include "HandleClientReversi.h"
#include "ThreadPool.h"
#define THREADS_NUM 5
//#define TASKS_NUM 5

using namespace std;

enum correctInput {
    GoodInput, BadInput,
};

class ReversiServer {
public:
    ReversiServer(int port, HandleClientReversi &handleClient);
    void start();
    void stop();
    void getCloseFromUser();
    static void* gateFunctionServer(void* element);
    void serverFunc();
private:
    int port;
    int serverSocket; // the socket's file descriptor;
    HandleClientReversi &m_handleClient;
    bool stopServer;
    ThreadPool pool;

};


#endif //OTHELLO_REVERSISERVER_H