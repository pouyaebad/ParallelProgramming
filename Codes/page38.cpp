// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
    int  sockets[2];
    char msgBuff[1024];

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0)
        return - 1;

    if (0 == fork())
    {
        const char msg1[]{ "Hi From Process 1" };

        close(sockets[0]);
        if (read(sockets[1], msgBuff, sizeof(msgBuff)) < 0)
            std::cout << "Process 1: Socket Reading Error\n";

        std::cout << "Rceived in Process 1: " << msgBuff << std::endl;

        if (write(sockets[1], msg1, sizeof(msg1)) < 0)
            std::cout << "Process 1: Socket Writing Error\n";
        close(sockets[1]);
    }
    else
    {
        const char msg2[]{ "Hi From Process 2" };

        close(sockets[1]);
        if (write(sockets[0], msg2, sizeof(msg2)) < 0)
            std::cout << "Process 2: Socket Writing Error\n";

        if (read(sockets[0], msgBuff, sizeof(msgBuff)) < 0)
            std::cout << "Process 2: Socket Reading Error\n";

        std::cout << "Rceived in Process 2: " << msgBuff << std::endl;

        close(sockets[0]);
    }
}

// Printed Result on Screen:
//              			"Rceived in Process 1: Hi From Process 2"
//              			"Rceived in Process 2: Hi From Process 1"
