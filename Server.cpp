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

Server::Server(int port) : port(port), serverSocket(0),pooly(THREADS_NUM) {
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
    threads.clients.push_back(thread);

    int rc = pthread_create(&thread, NULL, connect, (void *) &threads);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }

    exitSockets(threads);
}



    // Handle requests from a specific client
 void* Server::connect(void* threads) {
        struct TheThreads *args = (struct TheThreads *) threads;

        struct sockaddr_in clientAddress1;
        socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress1);


        while (true) {

            cout << "Waiting for clients connections..." << endl;


            int player = accept(args->Socket, (struct sockaddr *)&clientAddress1, &clientAddressLen);
            cout << "Player connected" << endl;
            if (player == -1)
                throw "Error on accept player";

            args->s->getThreads().addTask(new Task(HandleClient::makeOrder, &player));


            /* pthread_t thread;
            args->clients.push_back(thread);

            int rc = pthread_create(&thread, NULL, HandleClient::makeOrder, (void *) &player);
            if (rc) {
                cout << "Error: unable to create thread, " << rc << endl;
                exit(-1);
            }*/
// Close communication with the client
        }


    }

void Server::exitSockets(TheThreads &threads) {

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

    /*for (int j = 1; j < threads.clients.size(); ++j) {
        pthread_cancel(threads.clients[j]);
    }*/
    pooly.terminate();

    cout << "SERVER IS CLOSED"<< endl;
}

ThreadPool Server::getThreads() {
    return pooly;
}




/*(int clientSocket1, int clientSocket2)
    int column, row ;

    // Read new coordinates arguments from the first client
        int n = read(clientSocket1, &row, sizeof (row));
        if (n == -1) {
            cout << "Error reading row coordinate" << endl;
            return false;
        }
        if (n == 0) {
            cout << "Player disconnected" << endl;
            return false;
        }

        n = read(clientSocket1, &column, sizeof(column));
        if (n == -1) {
            cout << "Error reading column coordinate" << endl;
            return false;
        }

    // Write the coordinates back to the second client
        n = write(clientSocket2, &row, sizeof(row));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return false;
        }
        n = write(clientSocket2, &column, sizeof(column));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return false;
        }
        return true;

}
 */