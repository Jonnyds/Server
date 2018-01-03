//
// Created by jonathan on 28/12/17.
//
#include <iostream>
#include <vector>
using namespace std;
#ifndef SERVER_GAMELIST_H
#define SERVER_GAMELIST_H
#pragma once
/**
 * A struct containing a single game (2 sockets of players and the name of the game).
 */
struct listGames {
    int xSocket;
    int oSocket;
    string nameGame;
};
/**
 * A singleton class that contains the list of games for the commands use.
 */
class GameList {

    public:
    /**
     * @return the current instance of the object.
     */
        static GameList *getInstance();
    /**
     * Adds a game to the list.
     * @param game to be added to the list.
     */
        void addGame(struct listGames game);
    /**
     * Deletes a game from the list.
     * @param game to be removed from the list.
     */
        void removeGame(struct listGames game);
    /**
     * @return the list of games.
     */
        vector<listGames> getList() const;
    /**
     * Set the o player's socket
     * @param socket of the o player
     * @param index in the list
     */
        void setOsocket(int socket, int index);

    private:
        GameList() {}; // Private c'tor
        GameList(const GameList &other); // Private copy c'tor
        ~GameList() {};// Private destructor.
        static GameList *instance;// The instance of the object.
        vector<listGames> list;// The list of games.
};


#endif //SERVER_GAMELIST_H
