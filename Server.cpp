/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Server.h"
#include "HandleClient.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <cstdlib>
#include "GameList.h"

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define THREADS_NUM 3

Server::Server(int port) : port(port), serverSocket(0) {
    pooly = new ThreadPool(THREADS_NUM);
    //Server::serverSocket = 0;
    cout << "Server connected" << endl;
}

void Server::start() {


    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }

    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }

    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    TheThreads threads;
    threads.Socket = serverSocket;
    threads.s = this;
  //  threads.clients.push_back(thread);

    int rc = pthread_create(&thread, NULL, connect, (void *) this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }

    exitSockets();
}



    // Handle requests from a specific client
 void* Server::connect(void* threads) {
        Server *args = (Server *) threads;

        struct sockaddr_in clientAddress1;
        socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress1);


        while (true) {

            cout << "Waiting for clients connections..." << endl;


            int player = accept(args->getserversocket(), (struct sockaddr *)&clientAddress1, &clientAddressLen);
            cout << "Player connected" << endl;
            if (player == -1)
                throw "Error on accept player";

            Task *t = new Task(HandleClient::makeOrder,&player);
            args->getThreads()->addTask(t);

        }


    }

void Server::exitSockets() {

    int n;
    string cmd;
    cout << "Waiting for exit command" << endl;
    cin >> cmd;
    while (cmd != "exit") {
        cin >> cmd;
    }


    GameList* gl = GameList::getInstance();

    int closesocket = -4;

    for (int i = 0; i < gl->getList().size(); ++i) {
        n = write(gl->getList()[i].xSocket,&closesocket, sizeof(closesocket));
        n = write(gl->getList()[i].xSocket,&closesocket, sizeof(closesocket));
        close(gl->getList()[i].xSocket);
        if(gl->getList()[i].oSocket != -5) {
            n = write(gl->getList()[i].oSocket,&closesocket, sizeof(closesocket));
            n = write(gl->getList()[i].oSocket,&closesocket, sizeof(closesocket));
            close(gl->getList()[i].oSocket);
        }
    }
    pooly->terminate();


    cout << "SERVER IS CLOSED"<< endl;
}

ThreadPool* Server::getThreads() {
    return pooly;
}

int Server::getserversocket() {
    return serverSocket;
}
