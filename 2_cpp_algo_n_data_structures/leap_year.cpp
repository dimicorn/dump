#include <iostream>
using namespace std;
int main() {
    long long int x;
    cin >> x;
    if (x%4==0 and x%100!=0){
        cout << "YES";
    }
    else if (x%400==0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
