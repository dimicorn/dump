#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Man{
    string name;
    string numb;
    long int money;
};

bool comporator (Man q, Man w) {
    if (q.money != w.money) return q.money > w.money;
    else {
        if (q.name != w.name) {
            return q.name < w.name;
        }
        else {
            return q.numb < w.numb;
        }
    }
}


int main () {
    int n;
    cin >> n;
    vector<Man> ppl(n);
    for (int i = 0; i < n; ++i) {
        cin >> ppl[i].name >> ppl[i].numb >> ppl[i].money;
    }
    sort(ppl.begin(), ppl.end(), comporator);
    for (int i = 0; i < min(n, 10); ++i){
        cout << ppl[i].name << " " << ppl[i].numb << " " << ppl[i].money << endl;
    }
    return 0;
}
