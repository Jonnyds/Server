//
// Created by sahar on 12/20/17.
//

#include <map>
#include "Command.h"

using namespace std;

#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

class CommandsManager {

public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command, vector<string> args);
private:
    map<string, Command *> commandsMap;
};

#endif //SERVER_COMMANDSMANAGER_H