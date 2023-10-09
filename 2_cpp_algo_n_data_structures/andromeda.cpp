#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, maxx, count;
    cin >> n;
    maxx = -1000000;
    count = 0;
    //int arr[n];

    int* arr = (int *) malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i<n; i++){
        if (arr[i] > maxx){
            maxx = arr[i];
        }
    }
    for (int i = 0; i<n; i++){
        if(maxx == arr[i]){
            count++;
        }
    }
    free(arr);
    cout << count;
    return 0;
}
