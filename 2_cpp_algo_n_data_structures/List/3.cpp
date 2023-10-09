#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int pop(Node** head, int index)
{
    if (index == 0)
    {
        int a = (**head).value;
        Node* i = (*head);
        (*head) = (**head).next;
        free(i);
        return a;
    }

    if (index != 0)
    {
        Node* numb_i = *head;
        for (int i = 0; i < index; i++)
        {
            if (numb_i -> next != NULL)
            {
                if (i == index - 1)
                {
                    int num = (numb_i -> next) -> value;
                    Node* a = numb_i -> next;
                    numb_i -> next = numb_i -> next -> next;
                    free(a);
                    return num;
                }
                numb_i = numb_i -> next;
            }
        }
    }
}