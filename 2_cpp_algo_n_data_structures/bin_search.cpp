#include <iostream>
using namespace std;
int BinarySearch(int A[], int key, int n){
    int left = 0, right = n, mid;
    while (left <= right){
        mid = left + (right-left)/2;
        if (key < A[mid]) {
            right = mid-1;
        }
        else if (key > A[mid]) {
            left = mid+1;
        }
        else {
            return mid;
        }
    }
    return -1;
}
int main(){
    int n, key;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    cout << "Array: ";
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << "Key: ";
    cin >> key;
    if (BinarySearch(arr, key, n) == -1){
        cout << "No elem";
    }
    else {
        cout << "Elem Index" << BinarySearch(arr, key, n);
    }
    return 0;
}