/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <sys/param.h>
#include <vector>

using  namespace std;

struct TheThreads {
    vector<pthread_t> clients;
    int Socket;
};

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

    void exitSockets(TheThreads &threads);

private:
    /**
     * Handles the connecting of new client to the server (operates in a thread).
     * @param clientSocket1 the client's socket.
     */
    static void* connect(void* threads);
    int port; // the server's port.
    int serverSocket; // the server's socket.
    pthread_t thread; // the connect function's thread.
};

#endif //SERVER_SERVER_H