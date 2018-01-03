//
// Created by jonathan on 20/12/17.
//

#include "ListGamesCommand.h"
#include "GameList.h"
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

void ListGamesCommand::execute(string args, int socket) {

    GameList* gl = GameList::getInstance();
    vector<listGames> vgl = gl->getList();
    int n, len = vgl.size();
    char name[50];
    n = write(socket,&len,sizeof(len));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        exit(-1);
    }
    for (int j = 0; j < vgl.size() ; ++j) {
        if(vgl[j].oSocket == NULL) {
            strcpy(name,vgl[j].nameGame.c_str());
            n = write(socket,name, strlen(name));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
                exit(-1);
            }
        }
    }




}