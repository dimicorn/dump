#include <iostream>
using namespace std;
int main() {
    long long int x;
    cin >> x;
    for(int i=1; i<=x;i++){
        if(x%i==0 and i!=1 and i!=x){
            cout << i << endl;
            x = x/i;
            i = 1;
        }
    }
    cout << x;
    return 0;
}
