// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp -std=c++11
// On Windows      : Visual Studio (MSVC)
//

#include <iostream>
#include <thread>


void f(int* numbers, int* sum, int* counter)
{
    static int this_function_called_howmany_times{};

    *counter = ++this_function_called_howmany_times;
    
    *sum = *numbers + *(numbers + 1);
}



int main()
{
    int nums[] = { 33, 12, -5, 15 };
    int subTot[2], counter{};

    std::thread t1(f, &(nums[0]), &(subTot[0]), &counter); // counter will be 1
    std::cout << "Thread 1 is created" << std::endl;

    std::thread t2(f, &(nums[2]), &(subTot[1]), &counter); // counter will be 2


    t1.join();
    t2.join();

    std::cout << "function f() is called " << counter << " times" << std::endl;

    int grand_total{ subTot[0] + subTot[1] };
    std::cout << "Sum of all numbers is: " << grand_total << std::endl;
}

// Printed Result: function f() is called 2 times
//                 grand_total = 55
