#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int rank, size, length, i;
    if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    length = size * size;
    int root[length], count[size], disp[size], arr[rank + 1];
    for (i = 0; i < length; ++i) {
        root[i] = 0;
    }
    for (i = 0; i < size; ++i) {
        count[i] = i + 1;
        disp[i] = i * (i + 1);
    }
    for (i = 0; i < rank + 1; ++i) {
        arr[i] = rank + 1;
    }

    if (MPI_Gatherv(arr, rank + 1, MPI_INT, root, count, disp, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (rank == 0) {
        FILE *fptr;
        fptr = fopen("./output2.dat", "w");
        if (fptr == NULL) {
            printf("Couldn't open output file!\n");
            exit(1);
        }
        for (i = 0; i < length; ++i) {
            fprintf(fptr, "%d\n", root[i]);
        }
        fclose(fptr);
    }

    MPI_Finalize();

    return 0;
}
