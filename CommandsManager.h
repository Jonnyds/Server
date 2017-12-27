//
// Created by sahar on 12/20/17.
//

#include <map>
#include "Command.h"
#include <iostream>
using namespace std;

#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

struct listGames {
    int xSocket;
    int oSocket;
    string nameGame;
};

class CommandsManager {

public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command,string args);
private:
    map<string, Command *> commandsMap;
    vector<listGames> listGames;
};

#endif //SERVER_COMMANDSMANAGER_H