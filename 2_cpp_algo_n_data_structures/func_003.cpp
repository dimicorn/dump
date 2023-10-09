#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new){
    Cat* get_home_for_a_cats_pride(unsigned int n) {
        Cat* p = new Cat[n];
        for (int i = 0; i < n; i++) {
            p[i].name = new char[10];
        }
        return p;
    }

    void clear_home_of_a_cats_pride(Cat *cats, unsigned int n) {
        for (int i = 0; i < n; i++) {
            delete[] cats[i].name;
        }
        delete[] cats;
    }

}

int main() {
    unsigned int n, i;
    cin >> n;
    int *a = my_slightly_dumb_reallocation(NULL, 0, n / 2);
    for (i = 0; i < n / 2; i++)
        cin >> a[i];
    a = my_slightly_dumb_reallocation(a, n / 2, n);
    for (; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    cout << sum << endl;
    a = my_slightly_dumb_reallocation(a, n, n / 2);
    a = my_slightly_dumb_reallocation(a, n / 2, 0);
    a = my_slightly_dumb_reallocation(a, 0, 0);
    return 0;
}