//
// Created by jonathan on 20/12/17.
//

#include "StartCommand.h"
#include "GameList.h"



void StartCommand::execute(string args, int socket) {

    GameList* gameList = GameList::getInstance();
    struct listGames game;

    game.nameGame = args;
    game.xSocket = socket;
    game.oSocket = NULL;

    gameList->addGame(game);
}
