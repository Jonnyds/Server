/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

class Server {

public:
    /**
     * Server constructor.
     * @param port - the port number.
     */
    Server(int port);
    /**
     * setup the server (connections)
     */
    void start();

private:
    /**
     * handle reading and writing to and from both clients
     * @param clientSocket1 the first client's socket.
     * @return
     */
    static void* connect(void* clientSocket1);
    int port;
    static int serverSocket;
};

#endif //SERVER_SERVER_H