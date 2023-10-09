#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, v, l, t1, t2;
    cin >> a >> v >> l;
    t1 = sqrt(2*l / a);
    t2 = l / v;
    if (t1 < t2){
        cout << '1';
    }
    else{
        cout << '2';
    }
    return 0;
}
