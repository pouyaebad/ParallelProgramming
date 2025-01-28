// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <cstring>
#include <unistd.h>


int main()
{
    int pipe_fd[2];

    if (pipe(pipe_fd) < 0) // a pipe is created (with 2 descriptors)
        return -1;

    pid_t pid{ fork() }; // a new process is created
    if (pid < 0)
        return -2;

    if (0 == pid)
    {
        close(pipe_fd[0]);
        char msg[]{ "a Message from Process 1 (Child Process)" };

        write(pipe_fd[1], msg, std::strlen(msg)); // writing to pipe
    }
    else
    {
        const int MAXLEN{ 100 };
        char buffer[MAXLEN];

        close(pipe_fd[1]);
        ssize_t lenActual{ read(pipe_fd[0], buffer, MAXLEN) }; // reading from pipe

        buffer[lenActual] = 0;
        std::cout << buffer << std::endl;
    }
    std::cout << "Done \n";
}
// Printed Result on the Screen: "a Message from Process 1 (Child Process)"
