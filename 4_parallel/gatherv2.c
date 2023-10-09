#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>


int main(int argc, char *argv[]) {
    int rank, size, i, j, temp, length;
    if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    length = 0;
    int count[size], disp[size];
    srand(rank + 1);
    int len = rand() % 7 + 1;
    double arr[len];
    for (i = 0; i < len; ++i) {
        arr[i] = sqrt(rank);
    }
    if (MPI_Gather(&len, 1, MPI_INT, count, 1, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (rank == 0) {
        for (i = 0; i < size; ++i) {
            disp[i] = length;
            length += count[i];
       } 
    }

    double root[length];
    if (MPI_Gatherv(arr, len, MPI_DOUBLE, root, count, disp, MPI_DOUBLE, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) {
        FILE *fptr;
        fptr = fopen("./output3.dat", "w");
        if (fptr == NULL) {
            printf("Couldn't open output file!\n");
            exit(1);
        }    
        for (i = 0; i < size; ++i) {
            if (i != size - 1) {
                temp = disp[i + 1];
            } else {
                temp = length;
            }
            for (j = disp[i]; j < temp; ++j) {
                fprintf(fptr, "%lf ", root[j]);
            }
            fprintf(fptr, "\n");
        }
        fclose(fptr);
    }

    MPI_Finalize();

    return 0;
}
