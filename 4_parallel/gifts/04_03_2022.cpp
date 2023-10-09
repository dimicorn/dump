
#include <mpi.h>
#include <iostream>

int main(int argc , char *argv[])
{
    int size, rank;
    int data;
    if (MPI_Init(&argc,&argv) != MPI_SUCCESS)
    {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS)
    {
        MPI_Abort(MPI_COMM_WORLD, 2);
    }
    if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS)
    {
        MPI_Abort(MPI_COMM_WORLD, 3);
    }
    if (rank == 0)
    {
        data = 0;
        
        if (MPI_Send(&data, 1, MPI_INT, 1, 1, MPI_COMM_WORLD) != MPI_SUCCESS)
        {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        std::cout << "0 Send 0 to 1 \n";
        if(MPI_Recv(&data, 1, MPI_INT, size - 1 , 1, MPI_COMM_WORLD, NULL) == MPI_SUCCESS)
        {
            std::cout << rank << " recive " << data << " from " << size - 1 << "\n";
        }
    }
    else if (rank != size - 1)
    {
        if (MPI_Recv(&data, 1, MPI_INT, rank - 1, 1, MPI_COMM_WORLD, NULL) != MPI_SUCCESS)
        {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        
        std::cout << rank << " recive " << data << " from "<< rank -1 << "\n";
        data = data + rank;
        if (MPI_Send(&data, 1, MPI_INT, rank + 1, 1, MPI_COMM_WORLD) != MPI_SUCCESS)
        {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        
        std::cout << rank <<" send "<< data <<" to " << rank + 1 << "\n";

    }
    else
    {
        if (MPI_Recv(&data, 1, MPI_INT, rank - 1, 1, MPI_COMM_WORLD, NULL) != MPI_SUCCESS)
        {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        std::cout << rank << " recive " << data << " from " << rank - 1 << "\n";
        data = data + rank;
        if (MPI_Send(&data, 1, MPI_INT, 0, 1, MPI_COMM_WORLD) != MPI_SUCCESS)
        {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        std::cout << rank << " send " << data << " to " << 0 << "\n";
    }

    MPI_Finalize();

}
