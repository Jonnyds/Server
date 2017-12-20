//
// Created by sahar on 12/20/17.
//

#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H


#include "Command.h"

class PlayCommand: public Command {

    virtual void execute(vector<string> args);
};


#endif //SERVER_PLAYCOMMAND_H
