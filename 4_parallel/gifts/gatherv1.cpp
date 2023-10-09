#include <mpi.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>

int main(int argc, char* argv[])
{

    if (int error_code = MPI_Init(&argc, &argv) != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);}

    int rank, size;

    if (int error_code = MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);
    }

    if (int error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);
    }

    int length = size * size;

    int root_arr[length];
    for (int i = 0; i < length; i++){root_arr[i] = 0;}
    int counts[size];
    int displs[size];
    for (int i = 0; i < size; i++){counts[i] = i + 1; displs[i] = i * (i + 1);}
    int arr[rank + 1];
    for (int i = 0; i < rank + 1; i++){arr[i] = rank + 1;}

    if (int error_code = MPI_Gatherv(arr, rank + 1, MPI_INT, root_arr, counts, displs, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);
    }

    if (rank == 0){
        std::ofstream F("array.txt");
        if (F.is_open()){
            for (int i = 0; i < length; i++){F << root_arr[i] << "\n";}
        }
    }

    if (int error_code = MPI_Finalize() != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);
    }

    return 0;
}
