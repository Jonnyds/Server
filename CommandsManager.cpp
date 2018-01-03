/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

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
    commandsMap["close"] = new CloseCommand();

}

void CommandsManager:: executeCommand (ThreadArgs &threadArgs) {

    Command *commandObj = commandsMap[threadArgs.order];
    commandObj ->execute(threadArgs.name, threadArgs.socket);
}

CommandsManager:: ~CommandsManager() {

    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }
}