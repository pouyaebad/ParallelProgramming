// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp  -std=c++11
// On Windows      : Visual Studio (MSVC): use switch /std:c++11
//

#include <iostream>
#include <mutex>
#include <thread>

void f(int* numbers, int* sum)
{
    static std::mutex m;
    int total_this_thread{};

    total_this_thread += *numbers;
    total_this_thread += *(numbers + 1);


// The first thread reaching here, locks the lock (myLock) and continues running
// All of the next threads reaching here will wait till the lock, is being unlocked
    std::unique_lock<std::mutex> myLock(m);

    total_this_thread += *sum;

    std::cout << "Total of this thread is: " << total_this_thread << std::endl;

    *sum = total_this_thread;

// When a thread unlocks a lock, one another thread (if wants) can lock it again
    myLock.unlock(); 
}


int main()
{
    int numbers[] = { 33, 12, -5, 15 };
    int grandTot{};

    std::thread t1(f, &(numbers[0]), &grandTot); // Creating thread 1 & running it
    std::thread t2(f, &(numbers[2]), &grandTot); // Creating thread 2 & running it


    t1.join();           // Wait for thread 1 to finish
    t2.join();           // Wait for thread 2 to finish

    std::cout << "Sum of all numbers is: " << grandTot << std::endl;
}

// Printed Result: grandTot = 55 (always)
