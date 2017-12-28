//
// Created by jonathan on 27/12/17.
//

#include "GameManager.h"
#include "PlayCommand.h"
#include "CommandsManager.h"
#include "HandleClient.h"

GameManager::GameManager(listGames &lg) {

    playing.nameGame = lg.nameGame;
    playing.oSocket = lg.oSocket;
    playing.xSocket = lg.xSocket;

}

void GameManager::play() {

    PlayCommand pc;
    while(true) {
        if(!pc.execute(playing.xSocket, playing.oSocket)){
            break;
        }
        if(!pc.execute(playing.oSocket, playing.xSocket)){
            break;
        }
    }
    CommandsManager cm;
    ThreadArgs args;
    args.name = playing.nameGame;
    args.socket = playing.xSocket;
    args.order = "close";
    cm.executeCommand(&args);

}


