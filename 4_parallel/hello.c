#include <stdio.h>
#include <mpi.h>


int main(int argc, char *argv[]) {
    int flag;
    MPI_Initialized(&flag);
    if (flag == 1) {
        printf("Hello, I have been already initialized!\n");
        MPI_Finalize();
    } else {
        if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        } else {
            printf("Hello World!\n");
            MPI_Finalize();
        }
    }
    return 0;
}
// to run on cluster
// $ mpicc hello.c
// $ qsub run.sh
// $ qstat
