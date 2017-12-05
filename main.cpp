#include "Server.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
    Server server(8000);
  //  Server server1(8001);
    try {
        server.start();
    //    server1.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
    Server server1(8000);
    try {
        server1.start();
    } catch (const char *msg) {
        cout << "Cannot start server1. Reason: " << msg << endl;
        exit(-1);
    }
}