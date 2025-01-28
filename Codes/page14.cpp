// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp -std=c++11
// On Windows      : Visual Studio (MSVC)
//

#include <iostream>
#include <thread>

int numbers[] = { 33, 12, -5, 15 };
int subtotals[2];


void f1()
{
    subtotals[0] = numbers[0] + numbers[1];
}

void f2()
{
    subtotals[1] = numbers[2] + numbers[3];
}


int main()
{
    std::thread t1(f1);  // Creating thread 1 and running it
    std::thread t2(f2);  // Creating thread 2 and running it in parallel

    t1.join();           // Wait for thread 1 to finish
    t2.join();           // Wait for thread 2 to finish

    int grand_total{ subtotals[0] + subtotals[1]};

    std::cout << "Sum of all numbers is: " << grand_total << std::endl;
}
// Printed Result: 55
