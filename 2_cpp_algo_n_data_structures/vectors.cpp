#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct subvector {
    int *mas; // указатель на первый элемент
    unsigned int top; // длина вектора
    unsigned int capacity; // объем памяти
};
// capacity = sizeof(int)*2^n

void init(subvector *qv){
    qv -> mas = (int *)malloc(sizeof(int));
    qv -> top = 0;
    qv -> capacity = 1;
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

void resize(subvector *qv, unsigned int new_capacity){
    qv -> mas = (int*)realloc(qv -> mas,sizeof(int)*(new_capacity/4));
    qv -> capacity = new_capacity;
}

void shrink_to_fit(subvector* qv) {
    qv->capacity = qv->top;
}

void clear(subvector *qv){
    qv -> top = 0;
}

void destructor(subvector *qv){
    free(qv);
    subvector *qv_1;
    qv_1 -> mas = NULL;
    qv_1 -> top = 0;

}

void init_from_file(subvector* qv, std::string filename) {
    ifstream fromFile(filename, ios::in);
    if (fromFile.is_open()){
        int count = 0;
        fromFile >> count;
        for (int i = 0; i < count; ++i){
            int element;
            fromFile >> element;
            push_back(qv, element);
        }
    }
    else{
        cout << "The txt file doesn't open to reading" << endl;
    }
    fromFile.close();
}
int main(){

}