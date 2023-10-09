#include <stdio.h>
#include <math.h>
#include <omp.h>


int main(int argc, char *argv[]) {
    int N, i, thread, size, alf;
    double h, sum, result, x1, x2, f1, f2;

    if (fopen("N.dat", "r") == 0) {
        printf("Error no such file\n");
        return 1;
    }
    
    FILE *fl;
    fl = fopen("N.dat", "r");
    if (fscanf(fl, "%d", &N) != 1) {
        printf("Error fscanf\n");
    }
    fscanf(fl, "%d", &N);
    fclose(fl);

#pragma omp parallel shared(N) private(f1, f2, x1, x2, sum, i, alf, thread) reduction(+:result)
    {
        {
            size = omp_get_num_threads();
            thread = omp_get_thread_num();
            h = 2. / N;
            alf = (int) (1. * N / size);
            i = 0;
        }
        if (thread != (size - 1)) {
            while (i < alf) {
                x1 = h * (i + thread * alf);
                x2 = h * ((i + 1) + thread * alf);
                ++i;
                f1 = sqrt(4. - x1 * x1);
                f2 = sqrt(4. - x2 * x2);
                sum = h * (f1 + f2) / 2;
                result += sum;
            }
        }
        if (thread == (size - 1)) {
            i = thread * alf;
            while (i < N) {
                x1 = h * i;
                x2 = h * (i + 1);
                ++i;
                f1 = sqrt(4. - x1 * x1);
                f2 = sqrt(4. - x2 * x2);
                sum = h * (f1 + f2) / 2;
                result += sum;
            }
        }
    }
    printf("pi = %lf\n", result);

    return 0;
}
