// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp  -std=c++20
// On Windows      : Visual Studio (MSVC): use switch /std:c++20
//

#include <iostream>
#include <thread>

void f1()
{
    std::cout << " from Thread 1 \n";
}

void f2()
{
    std::cout << " from Thread 2 \n";
}


int main()
{
    std::jthread t1(f1);  // Creating thread 1 and running it
    std::jthread t2(f2);  // Creating thread 2 and running it in parallel

    // Now 3 Threads are running in parallel: t1, t2 and the main thread (program)
    
} // Now all 3 Threads are finished


// Printed Result: Both messages "from Thread 1" and "from Thread 2" will be
//                 printed but the order of printing depends to execution and
//                 is not determined (and is not fixed)
