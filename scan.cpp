// mpic++ -o scan scan.cpp
#include <stdio.h>
#include <cstdlib>
#include <mpi.h>
#include <iostream>
#if defined(_OPENMP)
#include <omp.h>
#endif
// Generate int random numbers in an array
void scan_seq(long* prefix_sum, const long* A, long n) {
  if (n == 0) return;
  prefix_sum[0] = A[0];
  for (long i = 1; i < n; i++) {
    prefix_sum[i] = prefix_sum[i-1] + A[i];
  }
}

#if defined(_OPENMP)
void scan_omp(long* prefix_sum, const long* A, long n) {
  // Suppose n is bigger than the number of threads
  if (n == 0) return;
  long* r;
  omp_set_num_threads(4);
  #pragma omp parallel shared(r)
  { 
    int p = omp_get_num_threads();
    int t = omp_get_thread_num();
    # pragma omp single
    {
      r= new long[p];
      // printf("Number of threads = %d\n",p);
    }
    // Fill out parallel scan: One way to do this is array into p chunks
    // Do a scan in parallel on each chunk, then share/compute the offset
    // through a shared vector and update each chunk by adding the offset
    // in parallel
    long start_index = t * n / p ;
    long end_index = (t + 1) * n / p;
    prefix_sum[start_index] = A[start_index];
    for (long i = start_index+1; i < end_index; i++) {      
      prefix_sum[i] = prefix_sum[i-1] + A[i];
    }    
    r[t]=prefix_sum[end_index-1];
    #pragma omp barrier
    long r_sum=0;
    for (size_t i = 0; i < t; i++)
    {
      r_sum += r[i];
    }
    for (long j = start_index; j < end_index; j++)
    {
      prefix_sum[j] += r_sum;
    } 
  }
  free(r);
}
#endif


int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);
    if (argc < 2) {
        printf("Usage: mpirun ./scan <vec_size>\n");
      abort();
    }
    long vec_size=atoi(argv[1]);
    int rank, size;
    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    printf("Rank %d/%d running on %s.\n", rank, size, processor_name);

    
    long N=size*vec_size;
    long* a;
    long* a_ref;
    long* b=new long[vec_size];
    long* prefix_sum_ref=new long[vec_size];
    if (rank==0)
    {
        a=new long[N];
        for (long i = 0; i < N; i++)
        {
            a[i] = rand();
            // a[i] = 1;
        }
        a_ref=new long[N];
        scan_seq(a_ref, a, N);
    } 
    MPI_Barrier(comm);  
    MPI_Scatter(a, vec_size, MPI_LONG, b, vec_size, MPI_LONG, 0, comm);
    MPI_Scatter(a_ref, vec_size, MPI_LONG, prefix_sum_ref, vec_size, MPI_LONG, 0, comm);
    long* prefix_sum=new long[vec_size];
#if defined(_OPENMP)
    scan_omp(prefix_sum, b, vec_size);
#else
    scan_seq(prefix_sum, b, vec_size);
#endif
    long *r=new long[size];
    MPI_Barrier(comm);
    MPI_Allgather(&prefix_sum[vec_size-1], 1, MPI_LONG, r, 1, MPI_LONG, comm);
    for (int i=0; i<rank;i++){
        for (long j=0; j<vec_size; j++){
            prefix_sum[j]+=r[i];
        }
    }
    printf("rank %d: sum %ld\n", rank,prefix_sum[vec_size-1]);
    long error=0;
    for (long i = 0; i < vec_size; i++)
    {
        if (prefix_sum[i]!=prefix_sum_ref[i])
        {
            error++;
        }
    }
    printf("rank %d: ,error %ld\n", rank,error);
    MPI_Finalize();
}