/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H


#include "Command.h"
/*
 * Inheriting from the Command interface this class closes the sockets when a game is done.
 */
class CloseCommand: public Command {

public:
    /**
     * Executes the command chosen.
     * @param args containing the arguments such as game name
     * @param socket of the player who requested the command
     */
    virtual void execute(string args,int socket);

};


#endif //SERVER_CLOSECOMMAND_H
