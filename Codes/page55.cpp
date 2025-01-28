// Pre - requirement : openMPI (as described in the previous page)
// 
// On Linux          : mpic++ ./file_name.cpp                    (to compile)
//                     mpirun --use-hwthread-cpus -n 4 ./a.out   (to run)
//

#include<iostream>
#include<mpi.h>

int main(int argc, char* argv[])
{
	int size, rank;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get unique ID of each process
	MPI_Comm_size(MPI_COMM_WORLD, &size); // get total number of processes

	switch (rank)
	{
	case 0:
		std::cout << "from FIRST Process of " << size << " Processes\n";
		break;

	case 1:
		std::cout << "from SECOND Process of " << size << " Processes\n";
		break;

	case 2:
		std::cout << "from THIRD Process of " << size << " Processes\n";
		break;

	case 3:
		std::cout << "from FOURTH Process of " << size << " Processes\n";
		break;

	default:
		std::cout << "from ANOTHER Process of " << size << " Processes\n";
		break;
	}


	MPI_Finalize();
}

// Printed Result:Following sentences will be printed but with random order
// 				from FIRST Process of 4 Processes
// 				from THIRD Process of 4 Processes
// 				from SECOND Process of 4 Processes
// 				from FOURTH Process of 4 Processes
