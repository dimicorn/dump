#include <iostream>
using namespace std;
int main() {
    int v, money, u;
    string a, b;
    money = 0;
    cin >> v >> a;
    while(a != "A999AA"){
        if (v > 60){
            if (a[1]==a[2] and a[1]==a[3]){
                money += 1000;
            }
            else if (a[1]==a[2] or a[1]==a[3] or a[2]==a[3]){
                money += 500;
            }
            else{
                money += 100;
            }
        }
        cin >> u >> b;
        v = u;
        a = b;
    }
    cout << money;
    return 0;
}
