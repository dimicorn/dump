#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
    int size, rank, real, *t, *displs, i, jbeg, jend, tsize;
    double *u, *unew, delta, maxdelta, h, tau;
    double eps = 1.e-6;
    int N = 1;
    FILE* ff;
    if (MPI_Init_thread(&argc, &argv, MPI_THREAD_FUNNELED, &real) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_THREAD_FUNNELED > real) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if ((t = malloc(size * sizeof(int))) == NULL) {
        printf("Can't allocate memory for t\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) {
        if (argc != 2) {
            printf("Usage: exefile npoints\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        N = atoi(argv[1]);
        if (N == 0) {
            printf("Set N to 1000\n");
            N = 1000;
        } else {
            printf("Set N to %d\n", N);
        }
    }
    
    if (MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if ((u = malloc((N + 1) * sizeof(double))) == NULL) {
        printf("Can't allocate memory for u\n");
        free(t);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if ((unew = malloc((N + 1) * sizeof(double))) == NULL) {
        printf("Can't allocate memory for unew\n");
        free(u);
        free(t);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    for (i = 1; i < N; ++i) {
        u[i] = 0;
    }
    unew[0] = u[0] = 1.;
    unew[N] = u[N] = 0;

    h = 1. / N;
    tau = 0.5 * h * h;

    if (rank == size - 1) {
        jbeg = (rank * ((N - 1) / size)) + 1;
        jend = N - 1;
    } else {
        jbeg = (rank * ((N - 1) / size)) + 1;
        jend = ((rank + 1) * ((N - 1) / size));
    }
    while(1) {
#pragma omp parallel for
        for (i = jbeg; i <= jend; ++i) {
            unew[i] = u[i] + (tau / (h * h)) * (u[i - 1] - 2 * u[i] + u[i + 1]);
        }
        maxdelta = 0;
#pragma omp parallel for reduction(max : maxdelta) private(delta)
        for (i = jbeg; i <= jend; ++i) {
            delta = fabs(unew[i] - u[i]);
            if (delta > maxdelta) {
                maxdelta = delta;
            }
        }
        if (MPI_Reduce(&maxdelta, &delta, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        maxdelta = delta;
        if (MPI_Bcast(&maxdelta, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        if (maxdelta < eps) {
            break;
        }

        if (rank == 0) {
            if (MPI_Send(&unew[jend], 1, MPI_DOUBLE, 1, 2, MPI_COMM_WORLD) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            if (MPI_Recv(&unew[jend + 1], 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
        } else if (rank != size - 1) {
            if (MPI_Send(&unew[jbeg], 1, MPI_DOUBLE, rank - 1, 1, MPI_COMM_WORLD) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            if (MPI_Send(&unew[jend], 1, MPI_DOUBLE, rank + 1, 2, MPI_COMM_WORLD) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            if (MPI_Recv(&unew[jend + 1], 1, MPI_DOUBLE, rank + 1, 1, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            if (MPI_Recv(&unew[jbeg - 1], 1, MPI_DOUBLE, rank - 1, 2, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
        } else {
            if (MPI_Send(&unew[jbeg], 1, MPI_DOUBLE, rank - 1, 1, MPI_COMM_WORLD) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            if (MPI_Recv(&unew[jbeg - 1], 1, MPI_DOUBLE, rank - 1, 2, MPI_COMM_WORLD, NULL) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
        }
#pragma omp parallel for
        for (i = 1; i < N; ++i) {
            u[i] = unew[i];
        }
    }
    tsize = jend - jbeg + 1;
    if (MPI_Gather(&tsize, 1, MPI_INT, t, 1, MPI_INT, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if ((displs = malloc(size * sizeof(int))) == NULL) {
        printf("Can't allocate memory for displs\n");
        free(u);
        free(unew);
        free(t);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    displs[0] = 1;
    for (i = 1; i < size; ++i) {
        displs[i] = displs[i - 1] + t[i - 1];
    }
    if (MPI_Gatherv(&unew[jbeg], tsize, MPI_DOUBLE, u, t, displs, MPI_DOUBLE, 0, MPI_COMM_WORLD) != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if ((ff = fopen("heat_final_out.dat", "w")) == NULL) {
        printf("Can't open output file\n");
        free(t);
        free(u);
        free(unew);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) {
        for (i = 0; i < N + 1; ++i) {
            fprintf(ff, "%lf ", u[i]);
        }
    }
    fclose(ff);

    free(u);
    free(unew);
    free(t);
    free(displs);

    MPI_Finalize();

    return 0;
}
