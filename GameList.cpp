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
    pthread_mutex_t list_mutex;
    pthread_mutex_lock(&list_mutex);
    list.push_back(game);
    pthread_mutex_unlock(&list_mutex);
}

void GameList::removeGame(struct listGames game) {
    pthread_mutex_t list_mutex;
    pthread_mutex_lock(&list_mutex);
    list.erase(std::remove(list.begin(), list.end(), game), list.end());
    pthread_mutex_unlock(&list_mutex);
}

vector<listGames> GameList::getList() const {
    return vector<listGames>();
}


