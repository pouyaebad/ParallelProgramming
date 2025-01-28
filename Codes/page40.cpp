// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <unistd.h>
#include <signal.h>

void f(int sigNo) // Signal Handler 
{
    std::cout << "Signal Received in the Main (Parnet) Process, Number: " << sigNo;
    std::cout << std::endl;
}

int main()
{
    if (0 != fork())
    {
        signal(SIGUSR1, f);       // Defining Signal Handler for Signal SIGUSR1
    }
    else
    {
        sleep(1);
        kill(getppid(), SIGUSR1); // Sending SIGUSR1 signal to parent process
    }

    sleep(2);
}

// Printed Result on the Screen:
// 			"Signal Received in the Main (Parent) Process, Number: 10"
