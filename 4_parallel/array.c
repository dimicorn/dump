#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    int size, rank, N, n, begin, end, i;
    N = 120;
    if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1); 
    }   
    if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1); 
    }   
    if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1); 
    }   
    if (N % size != 0) {
        MPI_Abort(MPI_COMM_WORLD, 2); 
    } else {
        n = N / size;
    }   
    int arr[N];
    begin = rank * n;
    end = (rank + 1) * n - 1;
    for (i = 0; i < N; ++i) {
        if (i >= begin && i <= end) {
            arr[i] = rank;
        } else {
            arr[i] = -1; 
        }   
    }   
    if (rank == 0) {
        if (MPI_Gather(MPI_IN_PLACE, n, MPI_INT, arr, n, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1); 
        }   
        for (i = 0; i < N; ++i) {
            printf("%d ", arr[i]);
        }   
        FILE *fptr = fopen("./output.dat", "w");
        if (fptr == NULL) {
            printf("Couldn't open output file!");
            return -1; 
        }   
        for (i = 0; i < N; ++i) {
            fprintf(fptr, "%d\n", arr[i]);
        }   
        fclose(fptr);
    } else {
        if (MPI_Gather(arr + begin, n, MPI_INT, arr, n, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1); 
        }   
    }   

    MPI_Finalize();

    return 0;
}

