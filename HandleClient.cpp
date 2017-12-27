//
// Created by sahar on 12/27/17.
//

#include "HandleClient.h"
#include "CommandsManager.h"
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


HandleClient::HandleClient(int &socket): socket(socket) {}


static void HandleClient::makeOrder() {

    char* com;
    char* comSplit;
    char* doSplit;
    char* space = (char*) ' ';

    CommandsManager command = CommandsManager();

    int n = read(socket, &com, sizeof (com));
    if (n == -1) {
        cout << "Error reading command" << endl;
    }
    if (n == 0) {
        cout << "Player disconnected" << endl;
    }

    comSplit = strtok(com, space);
    doSplit = strtok(NULL, space);

    pthread_t thread;
    int rc = pthread_create(&thread, NULL, command.executeCommand(comSplit, doSplit), (void *) doSplit);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
    pthread_exit(NULL);
}