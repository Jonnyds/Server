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

using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port) : port(port), serverSocket(0) { cout << "Server connected" << endl; }

void Server::start() {
    pthread_t thread;
    int playernum = 0;

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

    // Define the client socket's structures
    struct sockaddr_in clientAddress1;
    int rc = pthread_create(&thread, NULL, connect, (void *) &clientAddress1);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }

    }



    // Handle requests from a specific client
static void* Server::connect(void* clientSocket) {
        while (true) {
            pthread_t thread;
            cout << "Waiting for clients connections..." << endl;

            // Accept a new client connection
            socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientSocket);
            int player1 = accept(serverSocket, (struct sockaddr *)&clientSocket, &clientAddressLen);
            cout << "Player 1 connected" << endl;
            if (player1 == -1)
                throw "Error on accept player1";

            HandleClient handle(player1);
            int rc = pthread_create(&thread, NULL, handle.makeOrder(), NULL);
            if (rc) {
                cout << "Error: unable to create thread, " << rc << endl;
                exit(-1);
            }

        }

// Close communication with the client
        close(player1);
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