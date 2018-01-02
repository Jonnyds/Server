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
#include <sstream>


HandleClient::HandleClient(int &socket1) {

    socket = socket1;
}

void *HandleClient::makeOrder(void *socket) {
    string comSplit;
    string scmd;
    char cmd[50];
    CommandsManager command = CommandsManager();

    while ((comSplit != "start") || (comSplit != "join")) {


        int n = read(*(int *)socket, &cmd, sizeof(cmd));

        if (n == -1) {
            cout << "Error reading command" << endl;
        }

        if (n == 0) {
            cout << "Player disconnected" << endl;
        }

        for (int i = 0; i < strlen(cmd); ++i) {
            scmd.append(1u ,cmd[i]);
        }
        string str(scmd);
        istringstream iss(str);

        iss >> comSplit;
        string doSplit;
        iss >> doSplit;
        ThreadArgs threadArgs;
        threadArgs.name = doSplit;

        threadArgs.order = comSplit;
        threadArgs.socket = *(int *)socket;

        command.executeCommand(threadArgs);
    }
    //pthread_exit(NULL);
}