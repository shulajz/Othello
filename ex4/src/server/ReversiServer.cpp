//
// Created by or on 12/4/17.
//;

#include "ReversiServer.h"
#include "../client/src/Tools.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <cmath>

#define MAX_CONNECTED_CLIENTS 2

ReversiServer::ReversiServer(int port): port(port),
                                        serverSocket(0),
                                        endGame(false),
                                        receiveMove(false), num_of_clients(0){
    // Init mutex
    pthread_mutex_init(&this->handle_client_locker, 0);
    pthread_mutex_init(&this->connect_client_locker, 0);
    cout << "Server" << endl;
}
void ReversiServer::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,
          sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {

        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress1;
    socklen_t clientAddressLen1;
    pthread_t thread;
    while (true) {
        ClientData* clientData;
        clientStoppedCloseAllClients = false;
        endGame = false;
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddress1, &clientAddressLen1);
        pthread_mutex_lock(&this->connect_client_locker);
        num_of_clients++;
        pthread_mutex_unlock(&this->connect_client_locker);
        cout << "Client connected" << num_of_clients << endl;
        if (clientSocket == -1){
            stop();
            throw "Error on accept";
        }
        clientData = new ClientData();
        clientData->clientSocket = clientSocket;
        clientData->server = this;

        int rc = pthread_create(&thread, NULL, gateFunction, (void*)clientData);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
        cout << "are u here?" << endl;
    }
}

void* ReversiServer :: gateFunction(void* element) {
    ClientData* data = (ClientData*)element;
    data->server->handleClient(element);

}

void ReversiServer::handleClient(void* element) {
    ClientData* data = (ClientData*)element;

    while(true) {
        string command;
        string args;
        readCommand(data->clientSocket, command, args);
        pthread_mutex_lock(&this->handle_client_locker);
        commandsManager.executeCommand(command, args, data);
        pthread_mutex_unlock(&this->handle_client_locker);
    }
    
}

void ReversiServer :: readCommand(int clientSocket, string &command, string &args) {
    char commandFromUser[50];
    int n = read(clientSocket, &commandFromUser, sizeof(commandFromUser));
    if (n == -1) {
        throw "Error reading move from the socket";
    }
//    std::string str2 = str.substr (3,5);     // "think"
//
//    std::size_t pos = str.find("live");      // position of "live" in str
//
//    std::string str3 = str.substr (pos);     // get from "live" to the end

    string buf(commandFromUser);
    stringstream ss(commandFromUser); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    cout<<"the command is: " << tokens[0] << endl;
    command = tokens[0];
//    args = tokens[1];
    for(int i = 1; i < tokens.size(); i++){//we're now in play
            args += tokens[i] + " ";
    }
    cout<<"args are: "<< args<<endl;
//    if(tokens.size() == 3) {
//        args += " " + tokens[2];
//        cout << tokens[2] << endl;
//    }

}


void ReversiServer::stop() {
    cout << "close server" << endl;
    close(serverSocket);
}

void ReversiServer::sendValueOfClient(int clientSocket1, int clientSocket2) {
    char player1 = '1';
    char player2 = '2';
    int n = write(clientSocket1, &player1, sizeof(player1));
    cout << "Write on ClientSocket1 he play Black ('x')" << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
    n = write(clientSocket2, &player2, sizeof(player2));
    cout << "Write on ClientSocket2 he play White ('o') " << endl;
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}

void ReversiServer::join(string args, int clientSocket){
    for(int i = 0; i < listOfGames.size(); i++) {
        if (args == listOfGames[i]->name) {
            listOfGames[i]->socket2 = clientSocket;
            sendValueOfClient(listOfGames[i]->socket1, listOfGames[i]->socket2);
            listOfGames[i]->status = Active;
            break;
        }
    }
//    pthread_exit(NULL);
}

void ReversiServer::play(int row, int col, int clientSocket){
    int moveToSendToOtherClient[2];
    moveToSendToOtherClient[0] = row;
    moveToSendToOtherClient[1] = col;
    cout<<"row: "<<moveToSendToOtherClient[0]
        << endl << "col: "<< moveToSendToOtherClient[1]<<endl;
//    string listOfAvailableGames;
    for(int i = 0; i < listOfGames.size(); i++) {
        if(clientSocket == listOfGames[i]->socket1) {
            int n = write(listOfGames[i]->socket2, &moveToSendToOtherClient,
                          sizeof(moveToSendToOtherClient));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                return;
            }
            return;
        } else if(clientSocket == listOfGames[i]->socket2) {
            int n = write(listOfGames[i]->socket1, &moveToSendToOtherClient,
                          sizeof(moveToSendToOtherClient));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                return;
            }
            return;
        }
    }
}

void ReversiServer::startCommand(string args, int clientSocket){
    int error = -1;
    for(int i = 0; i < listOfGames.size(); i++) {
        if (args == listOfGames[i]->name) {
            int n = write(clientSocket, &error, sizeof(error));
            cout << "send error - the name already exists in the list of games" << endl;
            if (n == -1) {
                cout << "Error writing to socket CommandStart" << endl;
                return;
            }
            return; //return from the method, the name is not available
        }
    }

    Game* game = new Game() ; //make new? shula
    game->name = args;
    game->socket1 =clientSocket;
    game->socket2 = 0;
    game->status = Waiting;
    ///lock ?
    listOfGames.push_back(game);
}

void ReversiServer::listGames(int clientSocket){
    string listOfAvailableGames;
    for(int i = 0; i < listOfGames.size(); i++) {
        if(listOfGames[i]->status == Waiting) {
            listOfAvailableGames += listOfGames[i]->name + "\n";
        }
    }
    char buff[256];
    strcpy(buff, listOfAvailableGames.c_str());
    int n = write(clientSocket, &buff, sizeof(buff));
    cout << "send the list of available games to client" << endl;
    if (n == -1) {
        cout << "Error writing to socket CommandGetList" << endl;
        return;
    }
}

void ReversiServer::close(int clientSocket){
//    string listOfAvailableGames;
    char buffClose[6] = "close";
    for(int i = 0; i < listOfGames.size(); i++) {
        if(listOfGames[i]->socket1 == clientSocket) {
            cout << "close Client1" << "i is " << i << endl;
            int n = write(listOfGames[i]->socket2, &buffClose, sizeof(buffClose));
            cout << "send the list of available games to client" << endl;
            close(listOfGames[i]->socket2);
            close(listOfGames[i]->socket1);
            pthread_exit(NULL);
            break;            
        } else if(listOfGames[i]->socket2 == clientSocket){
            cout << "close Client2" << endl;
            close(listOfGames[i]->socket2);
            close(listOfGames[i]->socket1);
            pthread_exit(NULL);
            break;
        }
    }
    cout << "before exit"<<endl;
    
    
    
}