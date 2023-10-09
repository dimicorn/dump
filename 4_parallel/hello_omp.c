#include <stdio.h>
#include <omp.h>


int main(int argc, char *argv[]) {
    printf("All threads %d\n", omp_get_num_procs());
#pragma omp parallel num_threads(6)
    {
        printf("Hello OMP!, thread %d, all worked %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
    printf("Thread %d, all worked %d\n", omp_get_thread_num(), omp_get_num_threads());

    return 0;
}
