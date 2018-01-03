//
// Created by jonathan on 20/12/17.
//

#include "ListGamesCommand.h"
#include "GameList.h"
#include <vector>
#include <unistd.h>
#include <cstdlib>

void ListGamesCommand::execute(string args, int socket) {

    GameList* gl = GameList::getInstance();
    vector<listGames> vgl = gl->getList();
    int n, len = vgl.size();
    n = write(socket,&len,sizeof(len));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        exit(-1);
    }
    for (int i = 0; i <vgl.size() ; ++i) {
        if(vgl[i].oSocket == NULL) {
            n = write(socket,&vgl[i].nameGame.c_str(),sizeof(vgl));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                exit(-1);
            }
        }
    }




}