#include <iostream>
using namespace std;
int main() {
    long long int x,n, max;
    max = 0;
    cin >> x;
    while (x!=0){
        if (x%2==0 and x>max){
            max = x;
        }
        cin >> n;
        x = n;
    }
    cout << max;
    return 0;
}
