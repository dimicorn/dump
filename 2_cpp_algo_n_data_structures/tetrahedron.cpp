#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a1, a2, a3, b1, b2, b3,
    c1, c2, c3, d1, d2, d3, det;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> c1 >> c2 >> c3;
    cin >> d1 >> d2 >> d3;
    a1 = a1 - b1;
    a2 = a2 - b2;
    a3 = a3 - b3;
    b1 = b1 - c1;
    b2 = b2 - c2;
    b3 = b3 - c3;
    c1 = c1 - d1;
    c2 = c2 - d2;
    c3 = c3 - d3;
    det = fabs(a1*b2*c3 + a2*b3*c1 + a3*b1*c2 - c1*b2*a3
    - a2*b1*c3 - a1*b3*c2)/6;
    printf("%.4lf", det);
    return 0;
}
