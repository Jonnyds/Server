/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Command.h"
#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

/*
 * Inheriting from the Command interface this class sets a new game and adds it to the list of games.
 */
class StartCommand: public Command {

public:

    /**
     * Executes the command chosen.
     * @param args containing the arguments such as game name
     * @param socket of the player who requested the command
     */
    virtual void execute(string args, int socket) ;

};


#endif //SERVER_STARTCOMMAND_H
