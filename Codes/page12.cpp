// Pre-requirement : None
//
// On Windows      : Visual Studio (MSVC)
// 

#include <iostream>
#include <Windows.h>


DWORD WINAPI f1(LPVOID lpParam)
{
    std::cout << " from Thread 1 \n";
    return 0;
}

DWORD WINAPI f2(LPVOID lpParam)
{
    std::cout << " from Thread 2 \n";
    return 0;
}


int main()
{
    HANDLE  h_thread[2];

    // Creating thread 1 and running it
    h_thread[0] = CreateThread(NULL, 0, f1, NULL, 0, NULL);
    h_thread[1] = CreateThread(NULL, 0, f2, NULL, 0, NULL);


    // Now 3 Threads are running in parallel: t1, t2 and the main thread (program)


    // Wait for threads 1 and 2 to finish
    WaitForMultipleObjects(2, h_thread, TRUE, INFINITE);


    CloseHandle(h_thread[0]);
    CloseHandle(h_thread[1]);
}


// Printed Result: Both messages "from Thread 1" and "from Thread 2" will be
//                 printed but the order of printing depends to execution and
//                 is not determined (and is not fixed)
