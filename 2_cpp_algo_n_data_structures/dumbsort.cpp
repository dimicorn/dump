#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include <cstdlib>

using namespace std::chrono;
using std::cout;
using std::cin;
using std::string;
using namespace std;
int rand_uns(int min, int max) {
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    static default_random_engine e(seed);
    uniform_int_distribution<int> d(min, max);
    return d(e);
}
void output(string name, string file) {
    std::ofstream resout(file, std::ios::app);
    if (resout.is_open()) {
        resout << name << std::endl;
    }
    resout.close();
}
int main() {
    for (int j = 1000; j < 50000; j = j + 500){
        int* arr = (int*)malloc(sizeof(int)*j);
        for (int i = 0; i < j; ++i){
            arr[i] = rand_uns(0, 100000);
        }
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < j; ++i){
            for (int k = i; k < j; ++k){
                if(arr[i] > arr[k]){
                    swap(arr[i], arr[k]);
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "dumbsort.txt");
        free(arr);
    }
    return 0;
}
