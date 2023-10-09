#include <iostream>
//#pragma once

using namespace std;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push_left(Node ** head, int value){
    if(*head == NULL){
        *head = (Node*)malloc(sizeof(Node));
        (**head).value = value;
        (**head).next = NULL;
    }
    else{
        Node* a = (Node*)malloc(sizeof(Node));
        (*a).next = *head;
        (*a).value = value;
        *head = a;
    }
}