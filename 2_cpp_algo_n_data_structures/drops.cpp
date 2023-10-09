#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    float x, summ, r;
    summ = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        summ = summ + x * x;
    }
    r = sqrt(summ);
    printf("%.4lf", r);
    return 0;
}
