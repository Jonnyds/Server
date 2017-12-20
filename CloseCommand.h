//
// Created by sahar on 12/20/17.
//

#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H


#include "Command.h"

class CloseCommand: public Command {

public:
    CloseCommand();
    virtual void execute(vector<string> args);

};


#endif //SERVER_CLOSECOMMAND_H
