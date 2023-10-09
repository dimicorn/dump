#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push_left(Node** head, int value) {
    if (*head == nullptr) {
        *head = (Node*)malloc(sizeof(Node));
        (**head).value = value;
        (*head)->next = nullptr;
    }
    else {
        Node* a = (Node*)malloc(sizeof(Node));
        a->value = value;
        a->next = *head;
        *head = a;
    }
}

void reverse(Node** head){
    Node* arr = (Node*)malloc(sizeof(Node));
    arr->value = (*head)->value;
    arr->next = nullptr;
    Node* index = (*head)->next;
    free(*head);
    while (index != nullptr){
        push_left(&arr, index->value);

        Node* curr = index;
        index = index->next;
        free(curr);
    }
    *head = arr;
}