#include <iostream>
#include <cmath>

double func(double x) {
    return sqrt(4 - x * x);
};

int main() {
    int N;
    double s;
    double S = 0;
    double x0 = 0;

    std::cout << "number of trapezoids = ";
    std::cin >> N;
    double dx = 2. / N;
    for(int i = 0; i < N; ++i) {
        //std::cout << x0 << std::endl;
        //std::cout << func(x0) << std::endl;
        s = 0.5 * (func(x0) + func(x0 + dx)) * dx;
        S += s;
        x0 += dx;
    }    
    std::cout << "pi = " << S << std::endl;
    return 0;
}
