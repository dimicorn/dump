#include <iostream>
using namespace std;

int main()
{
    int num, n, s, av, sigma;
    cin >> num;
    s = 0;
    sigma = 0;
    int *Numbs = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> n;
        Numbs[i] = n;
        s = s + n;
    }
    av = s/num;
    for (int i = 0; i < num; i++){
        if (Numbs[i] > av){
            sigma = sigma + Numbs[i];
        }
    }
    cout << sigma;
    delete [] Numbs;
    return 0;
}