//
// Created by sahar on 12/20/17.
//

#include "CommandsManager.h"
#include "PlayCommand.h"
#include "CloseCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "StartCommand.h"



CommandsManager::CommandsManager() {}

void CommandsManager:: executeCommand (string command, vector<string> args) {

    Command *commandObj = commandsMap[command];
    commandObj ->execute(args);
}

CommandsManager:: ~CommandsManager() {

    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }
}