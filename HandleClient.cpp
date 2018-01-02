//
// Created by sahar on 12/27/17.
//

#include "HandleClient.h"
#include "CommandsManager.h"
#include "Server.h"
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


HandleClient::HandleClient(int &socket1) {

    socket = socket1;
}

void *HandleClient::makeOrder(void *socket) {

    char* com;
    char* comSplit;
    char* doSplit;
    char* space = (char*) ' ';

    CommandsManager command = CommandsManager();

    while ((comSplit != "start") || (comSplit != "join")) {
        int n = read(*(int *)socket, &com, sizeof(com));

        if (n == -1) {
            cout << "Error reading command" << endl;
        }

        if (n == 0) {
            cout << "Player disconnected" << endl;
        }

        comSplit = strtok(com, space);
        doSplit = strtok(NULL, space);
        ThreadArgs threadArgs;
        threadArgs.name = comSplit;
        threadArgs.order = doSplit;
        threadArgs.socket = *(int *)socket;

        command.executeCommand(threadArgs);
    }
    //pthread_exit(NULL);
}