#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main() {
    int n, k, count;
    vector<int> seq, sorted_seq, sorted_seq2;
    count = 1;
    cin >> n;
    int* line1 = (int*)malloc(sizeof(int)*(n+1));
    int* line2 = (int*)malloc(sizeof(int)*(n+1));
    for (int i = 0; i < n; ++i){
        cin >> k;
        seq.push_back(k);
        sorted_seq.push_back(k);
    }
    sort(sorted_seq.begin(), sorted_seq.begin()+n);
    sorted_seq2.push_back(sorted_seq[0]);
    for (int i = 1; i < n; ++i) {
        if (sorted_seq[i] != sorted_seq[i-1]) {
            sorted_seq2.push_back(sorted_seq[i]);
            ++count;
        }
    }
    for (int i = 0; i < n+1; ++i){
        line1[i] = 0;
    }
    for (int i = 0; i < count; ++i){
        for (int j = 0; j < n+1; ++j){
            if (j != 0 and seq[j-1] == sorted_seq2[i]){
                line2[j] = line1[j-1] + 1;
            }
            else if (j != 0){
                line2[j] = max(line2[j-1], line1[j]);
            }
            else{
                line2[j] = line1[j];
            }
        }
        int* t;
        t = line1;
        line1 = line2;
        line2 = t;
    }
    cout << line1[n];
    free(line1);
    free(line2);
    return 0;
}
