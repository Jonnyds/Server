//
// Created by jonathan on 20/12/17.
//
#include "Command.h"
#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

/*
 * Inheriting from the Command interface this class sets the second socket to a game and operates
 * the game manager.
 */
class JoinCommand: public Command {

public:
    /**
     * Executes the command chosen.
     * @param args containing the arguments such as game name
     * @param socket of the player who requested the command
     */
    virtual void execute(string args, int socket);
};


#endif //SERVER_JOINCOMMAND_H
