/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "StartCommand.h"
#include "GameList.h"



void StartCommand::execute(string args, int socket) {

    GameList* gameList = GameList::getInstance();

    for (int i = 0; i < gameList->getList().size(); ++i) {

        if (gameList->getList()[i].nameGame == args) {
            cout << "There is a game with this name already!!" << endl;
            return;
        }
    }

    struct listGames game;

    game.nameGame = args;
    game.xSocket = socket;
    game.oSocket = -5;

    gameList->addGame(game);
}