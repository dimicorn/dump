#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <list>
using namespace std::chrono;
using std::cout;
using std::cin;
using std::string;
using namespace std;

struct subvector{
    int* mas;
    int top, capacity;
};

void init(subvector *qv){
    qv -> mas = (int *)malloc(2 * sizeof(int));
    qv -> top = 0;
    qv -> capacity = 2;
}

void output(string name, string file) {
    std::ofstream resout(file, std::ios::app);
    if (resout.is_open()) {
        resout << name << std::endl;
    }
    resout.close();
}

void push_back(subvector* qv, int d){
    if (qv->capacity - qv->top == 0){
        qv->mas = (int*)realloc(qv->mas, (qv->top *2) * sizeof(int));
        (qv -> mas)[qv -> top] = d;
        qv->top ++;
        qv -> capacity = (qv -> capacity) *2;
    }
    else{
        qv->top ++;
        qv->mas[qv->top] = d;
    }
}

int pop_back(subvector* qv){
    int a = qv->mas[qv->top - 1];
    qv->top --;
    return a;
}

void push_front(subvector* qv, int d){
	if (qv->capacity - qv->top == 0){
		qv->mas = (int*)realloc(qv->mas, (qv->top * 2) * sizeof(int));
		for (int i = qv->top; i > 0;--i) {
            qv->mas[i] = qv->mas[i - 1];
        }
		qv->mas[0] = d;
		qv->top++;
        qv -> capacity = (qv -> capacity) *2;
	}
	else{
		for (int i = qv->top; i > 0;--i)
			qv->mas[i] = qv->mas[i - 1];
		qv->mas[0] = d;
		qv->top++;
	}
}

void time_push_back(int n, subvector * qv){
	for (int i = 1; i < n + 1; ++i){
        auto start = std::chrono::high_resolution_clock::now();
        push_back(qv, 1);
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "push_back.txt");
	}
}

void time_pop_back(int n, subvector * qv){
	for (int i = 1; i < n + 1; ++i) {
	    push_back(qv, 1);
    }
	for (int i = n; i > 0; --i){
        auto start = std::chrono::high_resolution_clock::now();
        int a = pop_back(qv);
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "pop_back.txt");
	}
}

void time_push_front(int n, subvector * qv){
	for (int i = 1; i < n + 1; ++i){
        auto start = std::chrono::high_resolution_clock::now();
		push_front(qv, 1);
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "push_front.txt");
	}
}

void time_push_back_list(list<int> * list, int n){
	for (int i = 1; i < n + 1; ++i){
        auto start = std::chrono::high_resolution_clock::now();
		list->push_back(1);
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "push_back_list.txt");
	}
}

void time_push_front_list(list<int>* list, int N){
	for (int i = 1; i < N + 1; ++i){
        auto start = std::chrono::high_resolution_clock::now();
		list->push_front(1);
        auto end = std::chrono::high_resolution_clock::now();
        nanoseconds fs = duration_cast<nanoseconds > (end - start);
        output(std::to_string(fs.count()), "push_front_list.txt");
	}
}
int main(){
	subvector v;
	int n, choice;
	list<int> list;
	init(&v);
	cin >> n;
	cin >> choice;
	if (choice == 0) {
        time_push_back(n, &v);
    }
	else if (choice == 1) {
        time_pop_back(n, &v);
    }
	else if (choice == 2) {
        time_push_front(n, &v);
    }
	else if (choice == 3) {
        time_push_back_list(&list, n);
    }
	else if (choice == 4){
        time_push_front_list(&list, n);
    }
	return 0;
}