#include <iostream>
using namespace std;
int main() {
    int x, max, count, n;
    max = 0;
    count = 0;
    cin >> x;
    while (x!=0){
        if (x>max){
            max = x;
            count = 0;
        }
        if (x == max){
            count++;
        }
        cin >> n;
        x = n;
    }
    cout << count;
    return 0;
}
