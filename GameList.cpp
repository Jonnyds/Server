//
// Created by jonathan on 28/12/17.
//

#include "GameList.h"
#include <iostream>

using namespace std;

GameList *GameList::instance = 0;

GameList *GameList::getInstance()
{
    if (instance == 0)
    {
        instance = new GameList;
    }
    return instance;
}

void GameList::addGame(struct listGames game) {

    list.push_back(game);
}

void GameList::removeGame(struct listGames game) {

    list.erase(std::remove(list.begin(), list.end(), game), list.end());
}

vector<GameList> GameList::getList() const {
    return vector<GameList>();
}
