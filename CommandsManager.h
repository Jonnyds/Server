//
// Created by sahar on 12/20/17.
//

#include <map>
#include "Command.h"
#include <iostream>
#include "HandleClient.h"
using namespace std;

#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H


class CommandsManager {

public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(ThreadArgs threadArgs);
private:
     map<string, Command *> commandsMap;
};

#endif //SERVER_COMMANDSMANAGER_H