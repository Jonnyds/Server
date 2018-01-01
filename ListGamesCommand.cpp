//
// Created by jonathan on 20/12/17.
//

#include "ListGamesCommand.h"
#include "GameList.h"
#include <vector>
#include <unistd.h>

void ListGamesCommand::execute(string args, int socket) {

    GameList* gl = GameList::getInstance();
    vector<listGames> vgl = gl->getList();
    vector<string> newvgl;

    for (int i = 0; i <vgl.size() ; ++i) {
        if(vgl[i].oSocket == NULL) {
            newvgl.push_back(vgl[i].nameGame);
        }
    }

    int n;
    n = write(socket,&newvgl,sizeof(newvgl));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        exit(-1);
    }
}