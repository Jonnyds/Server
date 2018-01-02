/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#include "Server.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
int main() {

    int port;
    ifstream inFile;
    inFile.open("settingServer.txt");
    inFile >> port;

    Server server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
    return 0;
}