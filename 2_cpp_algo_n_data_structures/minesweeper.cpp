#include <iostream>
using namespace std;
int main() {
    int n, m, k, y, x;
    cin >> n;
    cin >> m;
    cin >> k;
    int **map = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        map[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            map[i][j] = 0;
        }
    }
    for (int i = 0; i<k; i++){
        cin >> y;
        cin >> x;
        map[y-1][x-1]=-1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (map[i][j] == -1){
                if (i-1 >= 0 and j-1 >= 0){
                    if (map[i-1][j-1] != -1){
                        map[i-1][j-1]++;
                    }
                }
                if (i-1 >= 0 and j+1 <= m-1){
                    if (map[i-1][j+1] != -1){
                        map[i-1][j+1]++;
                    }
                }
                if (i+1 <= n-1 and j+1 <= m-1){
                    if (map[i+1][j+1] != -1){
                        map[i+1][j+1]++;
                    }
                }
                if (i+1 <= n-1 and j-1 >= 0){
                    if (map[i+1][j-1] != -1){
                        map[i+1][j-1]++;
                    }
                }
                if (j-1 >= 0){
                    if (map[i][j-1] != -1){
                        map[i][j-1]++;
                    }
                }
                if (j+1 <= m-1){
                    if (map[i][j+1] != -1){
                        map[i][j+1]++;
                    }
                }
                if (i+1 <= n-1){
                    if (map[i+1][j] != -1){
                        map[i+1][j]++;
                    }
                }
                if (i-1 >= 0){
                    if (map[i-1][j] != -1){
                        map[i-1][j]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++){
        free(map[i]);
    }
    free(map);
    return 0;
}
