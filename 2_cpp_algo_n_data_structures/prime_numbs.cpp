#include <iostream>
using namespace std;
int main() {
    long long int x, count;
    count = 0;
    cin >> x;
    for (int i=1; i <= x; i++){
        if (x%i==0){
            count++;
        }
    }
    if (count == 2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
