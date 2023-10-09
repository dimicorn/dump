#include <iostream>
using namespace std;
int main() {
    long long int a, b, r, temp;
    cin >> a;
    cin >> b;
    if (a<b){
        temp = a;
        a = b;
        b = temp;
    }
    if (a%b==0){
        cout << b << endl;
    }
    else{
        while (a%b>0){
            r = a%b;
            a = b;
            b = r;
        }
        cout << r;
    }

    return 0;
}
