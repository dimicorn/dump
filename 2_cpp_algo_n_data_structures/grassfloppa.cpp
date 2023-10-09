#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a, n, j, summ, count;
    vector<int> v;
    vector<int> path;
    j = -1;
    summ = 0;
    count = 0;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a;
        v.push_back(a);
    }
    while (j < n - 2){
        if (v[j + 1] > v[j + 2]){
            summ = summ + v[j + 2];
            path.push_back(j + 2);
            ++count;
            j = j + 2;
        }
        else{
            summ = summ + v[j + 1];
            path.push_back(j + 1);
            ++count;
            ++j;
        }

    }
    cout << summ << endl;
    for (int i = 0; i < count; ++i){
        cout << path[i] << ' ';
    }
    return 0;
}
