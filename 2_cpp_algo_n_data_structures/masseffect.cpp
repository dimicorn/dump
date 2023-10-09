#include <iostream>
using namespace std;
int main() {
    int n, mid;
    cin >> n;
    mid = (n - 1)/2;
    int* arr = (int *) malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cout<< arr[mid] << ' ';
    for(int i = 1; i<(n+1)/2; i++){
        cout << arr[mid-i] << ' ' << arr[mid+i] << ' ';
    }
    free(arr);
    return 0;
}
