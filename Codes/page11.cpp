// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp  -lpthread
//

#include <iostream>
#include <pthread.h>

void* f1(void*)
{
    std::cout << " from Thread 1 \n";
    return NULL;
}

void* f2(void*)
{
    std::cout << " from Thread 2 \n";
    return NULL;
}


int main()
{
    pthread_t tID1, tID2;

    pthread_create(&(tID1), NULL, &f1, NULL); // Creating thread 1 and running it
    pthread_create(&(tID2), NULL, &f2, NULL); // Creating thread 2 and running it 


    // Now 3 Threads are running in parallel: t1, t2 and the main thread (program)


    pthread_join(tID1, NULL); // Wait for thread 1 to finish
    pthread_join(tID2, NULL); // Wait for thread 2 to finish
}


// Printed Result: Both messages "from Thread 1" and "from Thread 2" will be
//                 printed but the order of printing depends to execution and
//                 is not determined (and is not fixed)
