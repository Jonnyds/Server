//
// Created by sahar on 12/20/17.
//
#include <iostream>
using namespace std;
#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H




class PlayCommand {
public:
PlayCommand(){}
    bool execute(int socket1, int socket2);
};


#endif //SERVER_PLAYCOMMAND_H
