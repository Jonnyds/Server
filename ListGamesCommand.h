//
// Created by jonathan on 20/12/17.
//
#include "Command.h"
#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H


class ListGamesCommand: public Command {

public:

    virtual void execute(string args, int socket) ;

};


#endif //SERVER_LISTGAMESCOMMAND_H
