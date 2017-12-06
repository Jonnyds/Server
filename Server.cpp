//
// Created by sahar on 03/12/17.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port) : port(port), serverSocket(0) { cout << "Noam is beautiful" << endl; }

void Server::start() {
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
    socklen_t clientAddressLen1;

    struct sockaddr_in clientAddress2;
    socklen_t clientAddressLen2;

    while (true) {
        cout << "Waiting for client connections..." << endl;
// Accept a new client connection
        int player1 = accept(serverSocket, (struct sockaddr *)&clientAddress1, &clientAddressLen1);
        cout << "Player 1 connected" << endl;
        if (player1 == -1)
            throw "Error on accept";
        playernum = 1;
        write(player1, &playernum, sizeof(playernum));

        int player2 = accept(serverSocket, (struct sockaddr *)&clientAddress2, &clientAddressLen2);
        cout << "Player 2 connected" << endl;
        if (player2 == -1)
            throw "Error on accept";
        playernum = 2;
        write(player2, &playernum, sizeof(playernum));

        handleClient(player1, player2);

// Close communication with the client
        close(player1);
        close(player2);
    }
}


// Handle requests from a specific client
void Server::handleClient(int clientSocket1, int clientSocket2) {
    int arg[2];
    char op;
    while (true) {
// Read new exercise arguments
        int n = read(clientSocket1, &arg[0], sizeof (arg[0]));
        if (n == -1) {
            cout << "Error reading arg1" << endl;
            return;
        }
        if (n == 0) {
            cout << "Player disconnected" << endl;
            return;
        }

        n = read(clientSocket1, &arg[1], sizeof(arg[1]));
        if (n == -1) {
            cout << "Error reading arg2" << endl;
            return;
        }

// Write the result back to the client
        n = write(clientSocket1, &arg, sizeof(arg));
        if (n == -1) { cout << "Error writing to socket" << endl;
            return;
        }
    }
}