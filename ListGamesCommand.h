//
// Created by jonathan on 20/12/17.
//
#include "Command.h"
#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

/*
 * Inheriting from the Command interface this class returns a list of games currently with
 * one player in them.
 */
class ListGamesCommand: public Command {

public:
    /**
     * Executes the command chosen.
     * @param args containing the arguments such as game name
     * @param socket of the player who requested the command
     */
    virtual void execute(string args, int socket) ;

};


#endif //SERVER_LISTGAMESCOMMAND_H
