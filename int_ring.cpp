// Compile: mpic++ -O3 -o ring int_ring.cpp
#include <stdio.h>
#include <cstdlib>
#include <mpi.h>
#include <iostream>

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);
    if (argc < 2) {
        printf("Usage: mpirun ./ring <N>\n");
    abort();
  }
    int N=atoi(argv[1]);
    int rank, size;
    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);
    if (!rank) printf("N=%d\n",N);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    printf("Rank %d/%d running on %s.\n", rank, size, processor_name);

    double latency1;
    double tt1 = MPI_Wtime();
    { 
        int message_in,message_out;
        /// Start the ring
        if (rank==0)
        {
            message_out=0;
            MPI_Send(&message_out, 1, MPI_INT, (rank+1)%size, 999, comm);
            // printf("Rank %d send %d\n", rank, message_out);
        }
        for (size_t i = 0; i < N; i++)
        {
            MPI_Recv(&message_in, 1, MPI_INT, (rank-1+size)%size, 999, comm, MPI_STATUS_IGNORE);
            message_out=message_in+rank;
            // printf("Rank %d received %d and send %d\n", rank, message_in, message_out);
            MPI_Send(&message_out, 1, MPI_INT, (rank+1)%size, 999, comm);
        }
        if (rank==1)
        {
            MPI_Recv(&message_in, 1, MPI_INT, (rank-1+size)%size, 999, comm, MPI_STATUS_IGNORE);
            // printf("Rank %d received %d\n", rank, message_in);
        }
        latency1=MPI_Wtime()-tt1;
    }
    if (!rank) printf("ring latency: %e ms\n", latency1/(N*size+1) * 1000);
    double tt2;
    double latency2;
    long message_size=2000000;
    {        
        char* message_out=new char[message_size];
        char* message_in=new char[message_size];
        for (long i = 0; i < message_size; i++)
        {
            message_out[i]=0;
        }
        tt2 = MPI_Wtime();
        if (rank==0)
        {
            MPI_Send(message_out, message_size, MPI_CHAR, (rank+1)%size, 999, comm);
        }
        for (size_t i = 0; i < N; i++)
        {
            MPI_Recv(message_in, message_size, MPI_CHAR, (rank-1+size)%size, 999, comm, MPI_STATUS_IGNORE);
            MPI_Send(message_out, message_size, MPI_CHAR, (rank+1)%size, 999, comm);
        } 
        if (rank==1)
        {
            MPI_Recv(message_in, message_size, MPI_CHAR, (rank-1+size)%size, 999, comm, MPI_STATUS_IGNORE);
        }
        latency2=MPI_Wtime()-tt2;
    }
    if (!rank) printf("ring bandwidth: %e GB/s\n", message_size*(N*size+1)/(latency2*1e9));      
    MPI_Finalize();

}
