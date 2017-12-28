//
// Created by jonathan on 28/12/17.
//
#include <iostream>
#include <vector>
using namespace std;
#ifndef SERVER_GAMELIST_H
#define SERVER_GAMELIST_H
#pragma once

struct listGames {
    int xSocket;
    int oSocket;
    string nameGame;
};
class GameList {

    public:
        static GameList *getInstance();
        void myMethod();

    private:
        GameList() {}; // Private c'tor
    GameList(const GameList &other); // Private copy c'tor
        ~GameList() {};

        static GameList *instance;
    vector<listGames> listGames;
};


#endif //SERVER_GAMELIST_H
