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
    for (int i = 0; i < list.size(); ++i) {
        if ((list[i].xSocket == game.xSocket) && (list[i].oSocket == game.oSocket)
            && (list[i].nameGame == game.nameGame)) {
            list.erase(list.begin() + i);
        }

    }
    pthread_mutex_unlock(&list_mutex);
}

vector<listGames> GameList::getList() const {
    return list;
}

void GameList::setOsocket(int socket, int index) {
    list[index].oSocket = socket;
}


