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

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
void output(string name, string file) {
    std::ofstream resout(file, std::ios::app);
    if (resout.is_open()) {
        resout << name << std::endl;
    }
    resout.close();
}
int rand_uns(int min, int max) {
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    static default_random_engine e(seed);
    uniform_int_distribution<int> d(min, max);
    return d(e);
}
int main(){
    for (int j = 1000; j < 100000; j = j + 500){
        int* arr = (int*)malloc(sizeof(int)*j);
        for (int i = 0; i < j; ++i){
            arr[i] = rand_uns(0, 100000);
        }
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, j-1);
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "quicksort.txt");
        free(arr);
    }

    return 0;
}