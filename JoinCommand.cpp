//
// Created by jonathan on 20/12/17.
//

#include "JoinCommand.h"
#include "GameManager.h"
#include "GameList.h"

void JoinCommand::execute(string args, int socket) {
    GameList* gl = GameList::getInstance();
    int i = 0;
    bool flag = false;
    for (i = 0; i < gl->getList().size() ; i++) {
        if (gl->getList()[i].nameGame == args) {
            gl->getList()[i].oSocket = socket;
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