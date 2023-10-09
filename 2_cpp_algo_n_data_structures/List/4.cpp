#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void remove(Node** head, int value)
{
    Node* numb_i = *head;
    if ((**head).value == value)
    {
        Node* a = *head;
        *head = (**head).next;
        free(a);
    }
    else
    {
        while (numb_i->next != NULL)
        {
            if ((numb_i->next)->value == value)
            {
                Node *a = numb_i->next;
                numb_i->next = numb_i->next->next;
                free(a);
                break;
            }
            numb_i = numb_i->next;
        }
    }
}
