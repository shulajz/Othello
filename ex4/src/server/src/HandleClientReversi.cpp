//
// Created by or on 12/25/17.
//
//
#include <unistd.h>
#include "HandleClientReversi.h"
#define SIZE_50 50
#include <pthread.h>

HandleClientReversi::HandleClientReversi(): commandsManager(listOfGames){
    pthread_mutex_init(&this->handle_client_locker, 0);

}

void HandleClientReversi :: sendCloseToEveryOne() {
    ClientData* data;
    string args;
    cout << "there is " << threads.size()<< " of open games" << endl;
    for(int i = 0; i < threads.size();i++){
        pthread_cancel(threads[i]);
        cout << "close open game " << i + 1 << endl;
    }
    commandsManager.executeCommand("killAll", args, data);
}

void HandleClientReversi::run(int clientSocket){
    if (clientSocket == -1){
        cout << "Error on accept";
        exit(-1);
    }
    cout << "Client "<< clientSocket<< " connected"  << endl;
    pthread_t thread1;
    ClientData* clientData = new ClientData();
    clientData->clientSocket = clientSocket;
    clientData->handleClient = this;
    //create thread that handle with the commands,
    // and after read command and execute it, the thread will ended.

    int rc = pthread_create(&thread1, NULL, gateFunction, (void*)clientData);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
}

void* HandleClientReversi :: gateFunction(void* element) {
    ClientData* data = (ClientData*)element;
//    cout << "hey1!!!!!!" << endl;
    data->handleClient->handleCommands(element);
}

void HandleClientReversi::handleCommands(void* element) {
    ClientData* data = (ClientData*)element;
    string command;
    string args;
    readCommand(data->clientSocket, command, args);
    pthread_mutex_lock(&this->handle_client_locker);
    commandsManager.executeCommand(command, args, data);
    pthread_mutex_unlock(&this->handle_client_locker);
    delete(data);
}

void HandleClientReversi :: readCommand(int clientSocket, string &command, string &args) {
    bool first_loop = true;
    char commandFromUser[SIZE_50];
    int n = read(clientSocket, &commandFromUser, sizeof(commandFromUser));
    if (n == -1) {
        cout<< "Error reading command from the socket" << endl;
        exit(-1);
    }
    string buf(commandFromUser);
    stringstream ss(commandFromUser); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    cout<<"the command of client"<< clientSocket <<" is: " << tokens[0] ;
    command = tokens[0];
    for(int i = 1; i < tokens.size(); i++){
        if (first_loop) {
            cout << " ,args are: ";
        }
        first_loop = false;
        args += tokens[i] + " ";
    }
    cout << args << endl;
}

void HandleClientReversi ::pushThread(pthread_t thread){
    threads.push_back(thread);
}

void HandleClientReversi ::eraseThread(pthread_t thread){
    for(int i = 0 ; i< threads.size(); i++){
        if (threads[i] == thread){
            threads.erase(threads.begin() + i);
        }
    }
}

HandleClient* HandleClientReversi:: getHandleClient(){
    return this;
}