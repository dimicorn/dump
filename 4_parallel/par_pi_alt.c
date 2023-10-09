#include <stdio.h>
#include <mpi.h>
#include <math.h>


double func(double x) {
    return sqrt(4 - x * x);
}

int main(int argc, char *argv[]) {
    int size, rank, i;
    int N = 10000;
    double s, S, x0;
    double dx = 2. / N;

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
        S = 0;
        x0 = 0;
        for (i = 0; i < N / size - 1; ++i) {
            s = 0.5 * (func(x0) + func(x0 + dx)) * dx;
            S += s;
            x0 += dx;
        }
        if (MPI_Send(&S, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        if (MPI_Send(&x0, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    } else if (rank != size - 1) {
        if (MPI_Recv(&S, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        if (MPI_Recv(&x0, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        for (i = 0; i < N / size - 1; ++i) {
            s = 0.5 * (func(x0) + func(x0 + dx)) * dx;
            S += s;
            x0 += dx;
        }
        if (MPI_Send(&S, 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        if (MPI_Send(&x0, 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    } else {
        if (MPI_Recv(&S, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        if (MPI_Recv(&x0, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        for (i = 0; i < N / size - 1; ++i) {
            s = 0.5 * (func(x0) + func(x0 + dx)) * dx;
            S += s;
            x0 += dx;
        }
        printf("%lf\n", S);
    }

    MPI_Finalize();

    return 0;
}

