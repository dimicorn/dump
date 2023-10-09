#include <iostream>
using namespace std;
int main() {
    int n, count;
    count = -1;
    float r, h, rho, mass;
    mass = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> r >> h >> rho;
        if (mass < r * r * h * rho){
            mass = r * r * h * rho;
            count = i;
        }
    }
    cout << count;
    return 0;
}
