#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int **mat1 = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        mat1[i] = (int*)malloc(n * sizeof(int));
    }
    int **mat2 = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        mat2[i] = (int*)malloc(n * sizeof(int));
    }
    int **mat3 = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        mat3[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat1[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat2[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mat3[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int r = 0; r < n; r++){
                mat3[i][j] = mat3[i][j] + mat1[i][r] * mat2[r][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat3[i][j] << ' ';
        }
        cout << endl;
    }


    for (int i = 0; i < n; i++){
        free(mat1[i]);
    }
    free(mat1);
    for (int i = 0; i < n; i++){
        free(mat2[i]);
    }
    free(mat2);
    for (int i = 0; i < n; i++){
        free(mat3[i]);
    }
    free(mat3);
    return 0;
}
