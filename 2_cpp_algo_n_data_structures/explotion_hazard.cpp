/*#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    int n, a, b, c;
    cin >> n;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    for (int i = 0; i < n; ++i){
        a = v[0];
        b = v[1];
        c = v[2];
        v[0] = v[0] + v[1] + v[2];
        v[1] = a + b + c;
        v[2] = a + b;
    }
    cout << v[0];
    return 0;
}
*/