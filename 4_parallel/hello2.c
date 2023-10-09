#include <stdio.h>
#include <mpi.h>


int main(int argc, char *argv[]) {
    int flag, size, rank, name_len;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Initialized(&flag);
    if (flag == 1) {
        if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        if (MPI_Get_processor_name(processor_name, &name_len) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        printf("Hello, I have been already initialized!\nProcessor %s, rank %d out of %d processors\n",
                processor_name, rank, size);
        MPI_Finalize();
    } else {
        if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
            MPI_Abort(MPI_COMM_WORLD, 1);
        } else {
            if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            if (MPI_Get_processor_name(processor_name, &name_len) != MPI_SUCCESS) {
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
            printf("Hello World! Processor %s, rank %d out of %d processors\n",
                    processor_name, rank, size);
            MPI_Finalize();
        }
    }
    return 0;
}

