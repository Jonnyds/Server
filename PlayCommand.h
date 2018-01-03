//
// Created by sahar on 12/20/17.
//
#include <iostream>
using namespace std;
#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H



/**
 * This class hold a function that reads from one player's socket to the second player's
 * socket.
 */
class PlayCommand {
public:
    /**
     * constructor.
     */
PlayCommand(){}
    /**
     * Executes the read and write of the coordinates from one socket to the other.
     * @param socket1 - the first socket the coordinates are read from.
     * @param socket2 - the second socket the coordinates are write to.
     * @return if the the game is not over false otherwise true.
     */
    bool execute(int socket1, int socket2);
};


#endif //SERVER_PLAYCOMMAND_H
