//
// Created by jonathan on 20/12/17.
//
#include "Command.h"
#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H


class JoinCommand: public Command {
    virtual void execute(vector<string> args);
};


#endif //SERVER_JOINCOMMAND_H
