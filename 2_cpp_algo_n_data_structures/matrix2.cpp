#include <iostream>
using namespace std;
int main() {
    int n, summ;
    summ = 0;
    cin >> n;
    int **arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(j == n-1-i){
                summ = summ + arr[i][j];
            }
        }
    }
    cout << summ;
    for (int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}
