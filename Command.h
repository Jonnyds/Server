//
// Created by sahar on 12/20/17.
//

#include <vector>
#include <string>

using namespace std;

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H


class Command {

public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};



#endif //SERVER_COMMAND_H





