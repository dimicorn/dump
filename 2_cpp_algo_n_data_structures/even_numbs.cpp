#include <iostream>
using namespace std;
int main() {
    long long int x, n, count;
    count = 0;
    cin >> x;
    while (x!=0){
        if (x%2==0){
            count++;
        }
        cin >> n;
        x = n;
    }
    cout << count;
    return 0;
}
