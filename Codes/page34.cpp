// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp    (older systems may need -lrt)
//

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

int main()
{
    if (0 == fork())
    {
        sem_t* sem{ sem_open("/mySem", O_CREAT, 0644, 1) };
        if (NULL == sem) return -1;

        std::cout << "Inside Process 1" << std::endl;

        sem_wait(sem); // Begining of Critical Section, decrement the semaphore
        std::cout << "Process 1 - Inside Critical Section Begining\n";

        sleep(4);

        std::cout << "Process 1 - Inside Critical Section End\n";

        sem_post(sem);  // End of of Critical Section, increment the semaphore
        sem_close(sem);

        sem_unlink("/mySem"); // Ask to remove the semaphore
    }
    else
    {
        sem_t* sem{ sem_open("/mySem", O_CREAT, 0644, 1) };
        if (NULL == sem) return -1;

        std::cout << "Inside Process 2" << std::endl;

        sem_wait(sem); // Begining of Critical Section, decrement the semaphore
        std::cout << "Process 2 - Inside Critical Section Begining\n";

        sleep(6);

        std::cout << "Process 2 - Inside Critical Section End\n";

        sem_post(sem);  // End of of Critical Section, increment the semaphore
        sem_close(sem);
    }
}
// Result: Only 1 process immediately enters to its critical section,
//         The other process waits at the beginning of its critical section,
//         Once the 1st process exits its own critical section,
//         Then the 2nd process enters to its critical section
