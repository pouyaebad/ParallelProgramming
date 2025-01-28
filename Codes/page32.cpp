// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <chrono>   // only for sleep function
#include <thread>   // only for sleep function
#include <cstring>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    const int SizeSMS { 1024 }; // SMS stands for      Shared Memory Segment

    if (0 == fork())
    {
        key_t key{ ftok("/home", 23) };              // generate a unique key
        int shmid{ shmget(key, SizeSMS, 0644 | IPC_CREAT) };//allocates SMS

        if (-1 == shmid) return -1;

        char* data1{ (char*)shmat(shmid, NULL, 0) }; // attach SMS to a pointer
        if((void*)-1 == data1) return -2;

        std::strcpy(data1, "Hi From Process 1");     // write to SMS

        shmdt(data1);                                // detach pointer from the SMS
    }
    else
    {           // wait for other process to finish writing to SMS
        std::this_thread::sleep_for(std::chrono::milliseconds(80)); 

        key_t key{ ftok("/home", 23) };              // generate a unique key
        int shmid{ shmget(key, SizeSMS, 0644 | IPC_CREAT) };//allocates SMS

        if (-1 == shmid) return -1;

        char* data2{ (char*)shmat(shmid, NULL, 0) }; // attach SMS to a pointer
        if((void*)-1 == data2) return -2;

        std::cout << data2 << std::endl;  // read from SMS

        shmdt(data2);                    // detach pointer from the SMS
        shmctl(shmid, IPC_RMID, NULL);   // destroy the shared memory segment
    }
}

// Result: "Hi From Process 1" will be printed from the receiver process
