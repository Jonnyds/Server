//
// Created by sahar on 12/27/17.
//



#ifndef SERVER_HANDLECLIENT_H
#define SERVER_HANDLECLIENT_H

#include <iostream>
#include <vector>
using namespace std;

struct ThreadArgs {
    string name;
    string order;
    int socket;
};


class HandleClient {
public:
    HandleClient(int &socket1);
    static void* makeOrder(void* socket);

private:
     int socket;
};


#endif //SERVER_HANDLECLIENT_H
