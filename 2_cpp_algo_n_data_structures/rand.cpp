#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int** path = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        path[i] = (int*)malloc(sizeof(int) * 2);
    }
    path[0][0] = arr[0];
    path[0][1] = -1;
    path[1][0] = arr[1];
    path[1][1] = -1;
    for (int i = 2; i < n; ++i) {
        path[i][0] = arr[i] + min(path[i - 1][0], path[i - 2][0]);
        if (path[i - 1][0] > path[i - 2][0]){
            path[i][1] = i - 2;
        }
        else{
            path[i][1] = i - 1;
        }
    }
    cout << path[n-1][0] << endl;
    string a = "";
    int b = path[n-1][1];
    a = to_string(n-1) + a;
    while (b != -1) {
        a = to_string(b) + " " + a;
        b = path[b][1];
    }
    cout << a;
    for (int i = 0; i < n; ++i) {
        free(path[i]);
    }
    free(path);
    free(arr);
}