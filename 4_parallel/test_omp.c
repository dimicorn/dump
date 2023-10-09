#include <stdio.h>
#include <omp.h>


int main(int argc, char *argv[]) {

#pragma omp parallel num_threads(3)
    {
        printf("Hi i was parallized\n");
    }
    printf("Hi\n");
    return 0;
}
