//
// Created by jonathan on 27/12/17.
//
#include "GameList.h"
#ifndef SERVER_GAMEMANAGER_H
#define SERVER_GAMEMANAGER_H


class GameManager {
public:
    GameManager(listGames &lg);
    void play();

private:
    listGames playing;

};


#endif //SERVER_GAMEMANAGER_H
