// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fifo_fd;

    if (mkfifo("/tmp/my_fifo", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH) < 0)
        std::cout << "Failed to Create FIFO, maybe it is already created \n";


    pid_t pid{ fork() };
    if (pid < 0)
        return -1;


    if (0 == pid)
    {
        if ((fifo_fd = open("/tmp/my_fifo", O_WRONLY)) < 0)
            return -2;

        char msg[]{ "a Message from Process 1 (Child Process)" };

        write(fifo_fd, msg, std::strlen(msg));
        close(fifo_fd);
    }
    else
    {
        const int MAXLEN{ 100 };
        char buffer[MAXLEN];


        if ((fifo_fd = open("/tmp/my_fifo", O_RDONLY)) < 0)
            return -3;

        ssize_t lenActual{ read(fifo_fd, buffer, MAXLEN) };

        buffer[lenActual] = 0;
        std::cout << buffer << std::endl;

        close(fifo_fd);
    }
    std::cout << "Done \n";
}
// Printed Result on the Screen: "a Message from Process 1 (Child Process)"
