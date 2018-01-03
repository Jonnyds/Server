/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */



#ifndef SERVER_HANDLECLIENT_H
#define SERVER_HANDLECLIENT_H

#include <iostream>
#include <vector>
using namespace std;
const int length = 50;
/**
 * Struct with the details of a single client.
 */
struct ThreadArgs {
    string name;
    string order;
    int socket;
};

/**
 * Reads commands from the client after connection.
 */
class HandleClient {
public:
    /**
     * constructor.
     * @param socket1 - the client's socket.
     */
    HandleClient(int &socket1);
    /**
     * Reads and executes commands given to the server by a client (in a thread).
     * @param socket - the client socket.
     */
    static void* makeOrder(void* socket);

private:
     int socket; // the clients socket.
};


#endif //SERVER_HANDLECLIENT_H
