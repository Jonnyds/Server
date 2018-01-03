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

/**
 * Executes all commands called by the player if valid.
 */
class CommandsManager {

public:
    /**
     * The commands manager constructor
     */
    CommandsManager();
    /**
     * The commands manager destructor.
     */
    ~CommandsManager();
    /**
     * Executes the correct command extracted from the commands map.
     * @param threadArgs the arguments needed to execute the command.
     */
    void executeCommand(ThreadArgs &threadArgs);
private:
     map<string, Command *> commandsMap; // the commands map locates the correct commands given a string.
};

#endif //SERVER_COMMANDSMANAGER_H