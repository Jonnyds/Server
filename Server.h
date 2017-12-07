//
// Created by sahar on 03/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

class Server {

public:
    Server(int port);
    void start();
    void stop();
private:
    bool handleClient(int clientSocket1, int clientSocket2) ;
    int port;
    int serverSocket;
};

#endif //SERVER_SERVER_H