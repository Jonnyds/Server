/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

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
    char cmd[length];
    int s = *(int *) socket;
    CommandsManager command = CommandsManager();

    while (true) {

        if (comSplit.compare("join") == 0) {
            break;
        }
        if (comSplit.compare("start") == 0){
            break;
        }

        int n = read(s, &cmd, sizeof(cmd));

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
        threadArgs.socket = *(int*)socket;

        command.executeCommand(threadArgs);
        memset(cmd, 0, 50);
        scmd.clear();
    }
}