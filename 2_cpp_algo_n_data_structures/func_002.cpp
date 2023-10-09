#include <iostream>
using namespace std;

int do_some_awesome_work(int* a, int* b){
    int* c;
    if (a <= b){
        c = b;
    }
    else {
        c = a;
    }
    return *c;
}

int main() {
    int e, f;
    cin >> e >> f;
    cout << do_some_awesome_work(&e, &f);
    return 0;
}
