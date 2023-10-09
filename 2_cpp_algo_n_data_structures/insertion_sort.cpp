#include <iostream>
using namespace std;

int i, j, key = 0, temp = 0;
void InsertSort(int* arr, int n){
    for (i = 0; i < n-1; ++i){
        key = i+1;
        temp = arr[key];
        for (j = i+1; j > 0; --j){
            if (temp < arr[j-1]){
                arr[j] = arr[j-1];
                key = j-1;
            }
        }
        arr[key] = temp;
    }
    for (i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

int main (){
    int n;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i){
        cin >> arr[i];
    }
    InsertSort(arr, n);
    free(arr);
    return 0;
}