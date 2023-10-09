#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <stdlib.h>


double sum(double start, double stop, int N) {
    double func(double x) {
        return sqrt(4 - x * x);
    }
    int i;
    double sum = 0;
    double step = (stop - start) / N;
    double s;
    
    for (i = 0; i <= N; ++i) {
        s = 0.5 * (func(start + i * step) + func(start + (i + 1) * step)) * step;
        sum += s;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int size, rank, N, i;
    double s, result;
    result = 0;
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
        FILE *fptr;
        // s = 0;
        fptr = fopen("./input.dat", "r");
        if (fptr == NULL) {
            printf("Couldn't open input file!\n");
            exit(1);
        }
        fscanf(fptr, "%d", &N);
        fclose(fptr);
        for (i = 1; i < size; ++i) {
            if (MPI_Send(&N, 1, MPI_INT, i, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
        }
        for (i = 1; i < size; ++i) {
            if (MPI_Recv(&s, 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            result += s;
        }
        printf("%lf\n", result);
    } else {
        int ibeg, iend;
        double start, stop;
        if (MPI_Recv(&N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        ibeg = (rank - 1) * ((int)N / size);
        if (rank != size - 1) {
            iend = rank * ((int)N / size) - 1;
        } else {
            iend = N - 1;
        }
        start = (double)ibeg / N * 2;
        stop = (double)iend / N * 2;
        s = sum(start, stop, iend - ibeg);
        if (MPI_Send(&s, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    }

    MPI_Finalize();

    return 0;
}

