#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

float func1(int a){
    return abs(sin(a));
}

float func2(int a){
    return (a*a - a) * abs(sin(a*a));
}

int main() {
    int n;
    float a;
    cin >> n;
    float* arr = (float*)malloc(sizeof(float) * (n+1));
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i < n + 1; ++i){
        if (sqrt(i) - int(sqrt(i)) < pow(10,-6)){
            arr[i] = min(func1(i-1)+arr[i-1], func2(int(sqrt(i-1))+arr[int(sqrt(i-1))]));
            //cout << func1(i-1)+arr[i-1] << ' ';
            //cout << func2(int(sqrt(i-1))+arr[int(sqrt(i-1))]) << endl;
        }
        else{
            arr[i] = func1(i-1) + arr[i-1];
            //cout << func1(i-1)+arr[i-1] << endl;
        }
    }
    a = arr[n];
    //cout << a;
    for (int i = 2; i < n + 1; ++i){
        if(i*i>n){
            a = min(a, func2(i*i));
            //cout << a << endl;
        }
    }
    /*for (int i = 0; i < n + 1; ++i){
        cout << arr[i] << ' ';
    }*/
    cout << a;
    free(arr);
    return 0;
}