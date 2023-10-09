#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void clear_list(Node** head)
{
    while ((**head).next != NULL)
    {
        Node* i = *head;
        (*head) = (**head).next;
        free(i);
    }
    free(*head);
    *head = NULL;
}

