#include <iostream>
using namespace std;

int main() {
    int n, t, count;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    count = 1;
    while (count != 0){
        count = 0;
        for (int i = 0; i < n - 1; ++i){
            if (arr[i] > arr[i+1]){
                t = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = t;
                ++count;
            }
        }
    }
    for (int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    free(arr);
    return 0;
}
