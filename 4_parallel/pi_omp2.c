#include <stdio.h>
#include <omp.h>
#include <math.h>


int main(int argc, char *argv[]) {
    int N, i;
    double h, sum, result, f1, f2, x1, x2;

    if (fopen("N.dat", "r") == 0) {
        printf("Error no such file\n");
        return 0;
    }
    
    FILE *fl;
    fl = fopen("N.dat", "r");
    if (fscanf(fl, "%d", &N) != 1) {
        printf("Error fscanf\n");
    }
    fscanf(fl, "%d", &N);
    fclose(fl);
    h = 2. / N;

#pragma omp parallel shared(N, h) private(f1, f2, x1, x2, sum) reduction(+:result)
    {
#pragma omp for
        for (i = 0; i < N; ++i) {
            x1 = h * i;
            x2 = h * (i + 1);
            f1 = sqrt(4. - x1 * x1);
            f2 = sqrt(4. - x2 * x2);
            sum = h * (f1 + f2) / 2;
            result += sum;
        }
    }

    printf("pi = %lf\n", result);

    return 0;
}
