#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        if (i==0 or i == n-1){
            for (int j = 0; j < m;j++){
                cout << '*';
            }
            cout << endl;

        }
        else{
            cout<< '*';
            for (int j = 0; j < m-2; j++){
                cout << ' ';
            }
            cout << '*' << endl;
        }
    }
    return 0;
}
