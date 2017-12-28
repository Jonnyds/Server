//
// Created by jonathan on 20/12/17.
//
#include "Command.h"
#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H


class StartCommand: public Command {

public:

   // StartCommand(int socket);
    virtual void execute(string args, int socket) ;

};


#endif //SERVER_STARTCOMMAND_H
