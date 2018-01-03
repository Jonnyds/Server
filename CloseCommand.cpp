/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include <unistd.h>
#include "CloseCommand.h"
#include "GameList.h"




void CloseCommand:: execute(string args, int socket) {

    GameList* gl = GameList::getInstance();

    for (int i = 0; i <gl->getList().size() ; ++i) {
        if(gl->getList()[i].nameGame == args) {
            close(gl->getList()[i].xSocket);
            close(gl->getList()[i].oSocket);
            gl->removeGame(gl->getList()[i]);
        }
    }


}