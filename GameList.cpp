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

void GameList::myMethod()
{
    cout << "Method of the Singleton class" << endl;
}