/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "JoinCommand.h"
#include "GameManager.h"
#include "GameList.h"

void JoinCommand::execute(string args, int socket) {
    GameList* gl = GameList::getInstance();
    int i = 0;
    bool flag = false;
    for (i = 0; i < gl->getList().size() ; i++) {
        if (gl->getList()[i].nameGame == args) {
            gl->setOsocket(socket,i);
            flag = true;
            GameManager gm(gl->getList()[i]);
            gm.play();
        }
    }
    if(!flag) {
        cout << "No such game exists" << endl;
        return;
    }
}