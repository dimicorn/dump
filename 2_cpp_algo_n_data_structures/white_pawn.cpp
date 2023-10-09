#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a;
    vector<string> c;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        c.push_back(a);
    }
    string b;
    cin >> b;
    int d = b[1] - 49;
    int** board = (int**)malloc(8 * sizeof(int*));
    for (int i = 0; i < 8; ++i) {
        board[i] = (int*)malloc(8 * sizeof(int));
    }
    for (int i = 0; i < 8; ++i) {
        if (i != b[0] - 97){
            board[d][i] = 0;
        }
        else{
            board[d][i] = 1;
        }
    }
    for (int i = d + 1; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = 0;
            int count = 0;
            for (int k = 0; k < n; ++k) {
                if (i == c[k][1] - 49 and j == c[k][0] - 97) {
                    if (j - 1 > -1){
                        board[i][j] = board[i][j] + board[i - 1][j - 1];
                    }
                    else{
                        board[i][j] = board[i][j] + 0;
                    }
                    if (j + 1 < 8){
                        board[i][j] = board[i][j] + board[i - 1][j + 1];
                    }
                    else{
                        board[i][j] = board[i][j] + 0;
                    }
                    count = 1;
                }
            }
            if (count == 0) {
                board[i][j] = board[i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        ans = ans + board[7][i];
    }
    cout << ans;
    for (int i = 0; i < 8; ++i) {
        free(board[i]);
    }
    free(board);
}