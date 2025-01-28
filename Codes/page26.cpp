// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <unistd.h>


int i;


void f(int* arg)
{
    (*arg)++;
    std::cout << "Inside function, i= " << ++i << ", arg= " << *arg << std::endl;
}


int main()
{
    int j{};

    i = 0;

    if (0 == fork())
        f(&j);
    else
        f(&j);

    std::cout << "i= " << i << ", j= " << j << std::endl; // will be printed twice
}
