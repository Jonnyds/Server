/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "Server.h"
#include "ThreadPool.h"
#include <sys/param.h>
#include <vector>

using  namespace std;



class Server {

public:
    /**
     * Server constructor.
     * @param port - the port number.
     */
    explicit Server(int port);
    /**
     * setup the server (connections)
     */
    void start();

    void exitSockets();
    ThreadPool getThreads();

private:
    /**
     * Handles the connecting of new client to the server (operates in a thread).
     * @param clientSocket1 the client's socket.
     */
    static void* connect(void* threads);
    int port; // the server's port.
    int serverSocket; // the server's socket.
    pthread_t thread; // the connect function's thread.
    ThreadPool pooly;
};

struct TheThreads {
    vector<pthread_t> clients;
    int Socket;
    Server *s;
};

#endif //SERVER_SERVER_H