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

bool unique_check(Node* head, int value)
{
    Node* index = head;
    while (index != nullptr)
    {
        if (index->value == value) {
            return false;
        }
        index = index->next;
    }

    return true;
}

int unique(Node* head){
    int uni = 0;
    Node* diff = (Node*)malloc(sizeof(Node));
    diff->value = head->value;
    diff->next = nullptr;
    Node* index = head->next;
    free(head);
    while (index->next != nullptr){
        if(unique_check(diff, index->value) == true){
            push_left(&diff, index->value);
        }

        Node* curr = index;
        index = index->next;
        free(curr);
    }
    Node* arr = diff;
    while (arr->next != nullptr){
        arr = arr->next;
        uni += 1;
    }
    return uni;
}