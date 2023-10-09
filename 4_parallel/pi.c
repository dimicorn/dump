#include <stdio.h>
#include <math.h>

double func(double x) {
    return sqrt(4 - x * x);
}

int main() {
    int N, i;
    double s;
    double S = 0;
    double x0 = 0;

    printf("Number of trapezoids = ");
    scanf("%d", &N);
    double dx = 2. / N;
    for (i = 0; i < N - 1; ++i) {
        s = 0.5 * (func(x0) + func(x0 + dx)) * dx;
        S += s;
        x0 += dx;
    }
    printf("pi = %lf\n", S);
    return 0;
}
