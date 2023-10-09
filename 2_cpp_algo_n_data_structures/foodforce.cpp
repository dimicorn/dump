#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x, y, f, sumx, sumy, alpha;
    int n;
    cin >> n;
    sumx = 0;
    sumy = 0;
    for (int i = 0; i < n; i++){
        cin >> x >> y >> f;
        alpha = f/sqrt(x*x + y*y);
        sumx = sumx + alpha*x;
        sumy = sumy + alpha*y;
    }
    printf("%.4lf", sumx);
    cout << ' ';
    printf("%.4lf", sumy);
    return 0;
}
