#include <iostream>
using namespace std;

int main() {
    int w, n, v, v_g;
    v_g = 0;
    cin >> w;
    cin >> n;
    int* values = (int*)malloc(sizeof(int) * n);
    int* volume = (int*)malloc(sizeof(int) * n);
    int* rucksack = (int*)malloc(sizeof(int) * (w+1));

    for (int i = 0; i < n; ++i){
        cin >> values[i] >> volume[i];
    }
    for (int i = 0; i < w+1; ++i){
        rucksack[i] = 0;
    }
    for (int i = 0; i < w+1; ++i){
        for (int j = 0; j < n; ++j){
            if (volume[j] <= i){
                v = rucksack[i - volume[j]];
                v_g = max(v + values[j], v_g);
            }
        }
        rucksack[i] = v_g;
        v_g = 0;
    }
    cout << rucksack[w];
    free(values);
    free(volume);
    free(rucksack);
    return 0;
}