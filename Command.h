//
// Created by sahar on 12/20/17.
//

#include <vector>
#include <string>

using namespace std;

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H

/*
 * A command interface containing the functions required to be called from the commands manager.
 */
class Command {

public:

    /**
     * Executes the command chosen.
     * @param args containing the arguments such as game name
     * @param socket of the player who requested the command
     */
    virtual void execute(string args, int socket) = 0;
    /*
     * A destructor to the  command
     */
    virtual ~Command() {}
};



#endif //SERVER_COMMAND_H





