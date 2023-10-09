#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double r, sumr, norm;
    int n;
    cin >> n;
    sumr = 0;
    float* X = (float*)malloc(n * sizeof(float));
    float* Y = (float*)malloc(n * sizeof(float));
    float* Z = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++){
        cin >> X[i] >> Y[i] >> Z[i];
    }
    cin >> norm;
    for (int i = 1; i < n; i++){
        r = sqrt((X[i]-X[i-1])*(X[i]-X[i-1]) + (Y[i]-Y[i-1])*(Y[i]-Y[i-1]) + (Z[i]-Z[i-1])*(Z[i]-Z[i-1]));
        sumr = sumr + r;
        if(sumr >= norm){
            cout << i;
            break;
        }
    }
    if (norm > sumr){
        cout << -1;
    }
    free(X);
    free(Y);
    free(Z);
    return 0;
}
