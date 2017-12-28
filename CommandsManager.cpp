//
// Created by sahar on 12/20/17.
//

#include "CommandsManager.h"
#include "PlayCommand.h"
#include "CloseCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "StartCommand.h"



CommandsManager::CommandsManager() {

    commandsMap["start"] = new StartCommand();
    commandsMap["list-games"] = new ListGamesCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["play"] = new PlayCommand();
    commandsMap["close"] = new CloseCommand();

}

void* CommandsManager:: executeCommand (void* threadArgs) {

    struct ThreadArgs *args = (struct ThreadArgs *) threadArgs;

    Command *commandObj = commandsMap[args->order];
    commandObj ->execute(args->name);
}

CommandsManager:: ~CommandsManager() {

    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }
}