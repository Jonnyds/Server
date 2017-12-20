//
// Created by sahar on 12/20/17.
//

#include "CommandsManager.h"







CommandsManager:: ~CommandsManager() {
    
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }
}