#include <iostream>
using namespace std;
int main() {
    int n, min, ind, t, count;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i){
        count = 0;
        for (int j = i; j < n; ++j){
            if (arr[i] > arr[j]){
                min = arr[j];
                ind = j;
                ++count;
            }
        }
        if (count != 0){
            t = arr[i];
            arr[i] = min;
            arr[ind] = t;
        }
    }
    for (int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    return 0;
}
