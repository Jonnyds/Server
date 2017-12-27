//
// Created by jonathan on 20/12/17.
//
#include "Command.h"
#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H


class StartCommand: public Command {

public:

    virtual void execute(string args) ;

};


#endif //SERVER_STARTCOMMAND_H
