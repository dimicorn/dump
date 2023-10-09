#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long int x;
    double t;
    cin >> x;
    t = log(x)/log(2);
    if (t-int(t)==0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
