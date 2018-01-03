//
// Created by jonathan on 27/12/17.
//
#include "GameList.h"
#ifndef SERVER_GAMEMANAGER_H
#define SERVER_GAMEMANAGER_H

/**
 * This class manages a game.
 */
class GameManager {
public:
    /**
     * Constructor.
     * @param lg the list of games.
     */
    GameManager(listGames &lg);
    /**
     * Calls the read and write to sockets commands and the close command at the end of a game.
     */
    void play();

private:
    listGames playing;// The current game's details.

};


#endif //SERVER_GAMEMANAGER_H
