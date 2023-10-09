#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int x, n, count, m, a, b, c, d;
    char down = 'v';
    char left = '<';
    cin >> n;
    x = n;
    count = 0;
    if (n>=60){
        while (n>=60){
            n=n/60;
            count ++;
        }
        for (int i=count; i>0; i--){
            m = x/int(pow(60, i));
            a = m/10;
            b = m%10;
            cout << string(a, left) << string(b, down)<< '.';
            x = x%int(pow(60, i));
        }
        c = x%int(pow(60, count))/10;
        d = x%int(pow(60, count))%10;
        cout << string(c, left) << string(d, down);
    }
    else{
        c = x/10;
        d = x%10;
        cout << string(c, left) << string(d, down);
    }
    return 0;
}
