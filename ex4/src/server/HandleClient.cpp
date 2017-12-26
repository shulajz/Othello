//
// Created by or on 12/25/17.
////

#include <unistd.h>
#include "HandleClient.h"

HandleClient::HandleClient() :commandsManager(listOfGames){
    pthread_mutex_init(&this->handle_client_locker, 0);
}

void HandleClient :: sendCloseToEveryOne() {
    int closeClients[2];
    closeClients[0] = Close;
    closeClients[1] = Close;
   // vector <Game*> listOfGames = *this->listOfGames;
    for (int i = 0; i < listOfGames.size(); i++) {
        int n = write(listOfGames[i]->socket1, &closeClients, sizeof(closeClients));
        if (n == -1) {
            throw "Error reading move from the socket";
        }
        close(listOfGames[i]->socket1);
        if(listOfGames[i]->socket2) {
            int n = write(listOfGames[i]->socket2, &closeClients, sizeof(closeClients));
            if (n == -1) {
                throw "Error reading move from the socket";
            }
            close(listOfGames[i]->socket2);
        }
    }
}
void HandleClient::run(int clientSocket){
    pthread_t thread1;
    ClientData* clientData;
    if (clientSocket == -1){
        throw "Error on accept";
    }
    cout << "Client "<< clientSocket<< " connected"  << endl;
    clientData = new ClientData();
    clientData->clientSocket = clientSocket;
    clientData->server = this;
    //create thread that handle with the commands,
    // and after read command and execute it, the thread will ended.
    int rc = pthread_create(&thread1, NULL, gateFunction, (void*)clientData);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
}

void* HandleClient :: gateFunction(void* element) {
    ClientData* data = (ClientData*)element;
    data->server->handleClient(element);

}

void HandleClient::handleClient(void* element) {
    ClientData* data = (ClientData*)element;
    string command;
    string args;
    readCommand(data->clientSocket, command, args);
    pthread_mutex_lock(&this->handle_client_locker);
    commandsManager.executeCommand(command, args, data);
    pthread_mutex_unlock(&this->handle_client_locker);
}

void HandleClient :: readCommand(int clientSocket, string &command, string &args) {
    bool first_loop = true;
    char commandFromUser[50];
    int n = read(clientSocket, &commandFromUser, sizeof(commandFromUser));
    if (n == -1) {
        throw "Error reading move from the socket";
    }
    string buf(commandFromUser);
    stringstream ss(commandFromUser); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    cout<<"the command of client"<< clientSocket<<" is: " << tokens[0] ;
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