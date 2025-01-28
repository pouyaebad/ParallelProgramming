// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <unistd.h>

int main()
{
	if (0 == fork())
	{
		std::cout << " from Process 2 (Child) \n";
	}
	else
	{
		std::cout << " from Process 1 (Parent) \n";
	}
}

// Printed Result: Both messages "from Process 1 (Parent)" & 
//                 "from Process 2 (Child)" will be printed but the order of
//                 printing depends to execution & is not determined (& not fixed)
