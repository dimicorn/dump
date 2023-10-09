#include <iostream>
using namespace std;
int main() {
    int wal, gobs, coins, count, inc, k, j, a, b;
    inc = 2; // счетчик шага
    k = 0;
    j = 0;
    a = 1;
    b = 0;
    coins = 0;
    count = 0;
    cin >> wal;
    int* Wal = (int*)malloc(sizeof(int) * wal); // монет в кошельке
    for (int i = 0; i < wal; i++){
        cin >> Wal[i];
    }
    cin >> gobs;
    int* Gobs = (int*)malloc(sizeof(int) * gobs); // монет у гоблина
    for (int i = 0; i < gobs; i++){
        Gobs[i] = 0;
    }
    for (int i = 0; i < wal; i++){
        coins = coins + Wal[i];
    }
    while (coins != 0) {
        if (Wal[j] == 0){
            for (; j < wal and Wal[j] == 0; j++) {
                inc++;
            }
            if (b-1 < 0){
                a++;
            }
            else{
                a = (b-1)%inc;
            }
        }
        if (b % inc == a){
            if (Gobs[b%gobs] == 0){
                k++;
            }
            Gobs[b%gobs]++;
            coins--;
            Wal[j]--;
            if (k == gobs){
                cout << "YES " << coins << endl;
                break;
            }
        }
        b++;
    }
    for (int i = 0; i < gobs; i++){
        if (Gobs[i] == 0){
            count++;
        }
    }
    if (count != 0){
        cout << "NO " << count;
    }
    free(Wal);
    free(Gobs);
    return 0;
}
