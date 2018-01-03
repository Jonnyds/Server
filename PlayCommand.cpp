//
// Created by sahar on 12/20/17.
//

#include <unistd.h>
#include "PlayCommand.h"

bool PlayCommand::execute(int socket1, int socket2) {
    int row , column;

    // Read new coordinates arguments from the first client

    int n = read(socket1, &row, sizeof (row));
    if (n == -1) {
        cout << "Error reading row coordinate" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Player disconnected" << endl;
        return false;
    }



    n = read(socket1, &column, sizeof(column));
    if (n == -1) {
        cout << "Error reading column coordinate" << endl;
        return false;
    }


    // Write the coordinates back to the second client

    n = write(socket2, &row, sizeof(row));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return false;
    }



    n = write(socket2, &column, sizeof(column));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return false;
    }

    return true;

}