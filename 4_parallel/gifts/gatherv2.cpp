#include <mpi.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
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

    int length = 0;
    int counts[size];
    int displs[size];

    srand(rank + 1);
    int len = rand() % 7 + 1;
    double *arr = new double[len];
    for (int i = 0; i < len; i++){arr[i] = sqrt(rank);}

    if (int error_code = MPI_Gather(&len, 1, MPI_INT, counts, 1, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);
    }

    if (rank == 0){
        for (int i = 0; i < size; i++){
            displs[i] = length;
            length += counts[i];
        }
    }

    double *root_arr = new double[length];

    if (int error_code = MPI_Gatherv(arr, len, MPI_DOUBLE, root_arr, counts, displs, MPI_DOUBLE, 0, MPI_COMM_WORLD) != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);
    }

    if (rank == 0){
        std::ofstream F("array.txt");
        if (F.is_open()){
            for (int i = 0; i < size; i++){
                int tmp = (i != size - 1) ? displs[i + 1] : length;
                for (int j = displs[i]; j < tmp; j++){
                    F << root_arr[j] << " ";
                }
                F << "\n";
            }
        }
    }

    if (int error_code = MPI_Finalize() != MPI_SUCCESS){
        std::cout << "error\n";
        MPI_Abort(MPI_COMM_WORLD, error_code);
    }

    return 0;
}

