#include <stdio.h>
#include <mpi.h>


int main(int argc, char *argv[]) {
    int size, rank, data;
    if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) {
        data = 0;
        if (MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        printf("0 send 0 to 1\n");
        if (MPI_Recv(&data, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        printf("%d receive %d from %d\n", rank, data, size - 1);
    } else if (rank != size - 1) {
        if (MPI_Recv(&data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        printf("%d receive %d from %d\n", rank, data, rank - 1);
        data += rank;
        if (MPI_Send(&data, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        printf("%d send %d to %d\n", rank, data, rank + 1);
    } else {
        if (MPI_Recv(&data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        printf("%d receive %d from %d\n", rank, data, rank - 1);
        data += rank;
        if (MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        printf("%d send %d to 0\n", rank, data);
    }

    MPI_Finalize();

    return 0;
}

