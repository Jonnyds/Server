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

void *HandleClient::makeOrder(void* targs) {
    struct TheThreads *args = (struct TheThreads *) targs;
    char* com;
    char* comSplit;
    char* doSplit;
    char* space = (char*) ' ';

    CommandsManager command = CommandsManager();

    while ((comSplit != "start") || (comSplit != "join")) {
        int n = read(socket, &com, sizeof(com));

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
        threadArgs.socket = socket;

        pthread_t thread;
        args->commands.push_back(thread);
        int rc = pthread_create(&thread, NULL, command.executeCommand, (void *) &threadArgs);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
    }
    //pthread_exit(NULL);
}