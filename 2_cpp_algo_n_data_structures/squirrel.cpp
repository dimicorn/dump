#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float h, vx, t, g, l;
    g = 9.81;
    cin >> h >> vx;
    t = sqrt(2*h/g);
    l = vx * t;
    printf("%.4lf", l);
    return 0;
}
