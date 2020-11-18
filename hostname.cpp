#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[])
{

    char name[100];
    double mm = 1.0;
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    gethostname(name, sizeof(name));
    
    mm = (mm+rank)*2;

    printf("Hello World from process %d / %d   host name: %s    result = %.15f\n", rank, size, name, mm);
    MPI_Finalize();

    return 1;

}

