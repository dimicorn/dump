#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void replace_all(Node* head, int old_value, int new_value) {
    Node* index = head;
    while (index->next != nullptr){
        if (index -> value == old_value){
            index->value = new_value;
        }
        index = index->next;
    }
}