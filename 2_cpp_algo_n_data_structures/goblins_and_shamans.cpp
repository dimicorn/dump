#include<iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node* next;
};


void end(Node** head, string comm)
{
    int gobl = 0;
    for (int i = 2;i < comm.length();++i)
    {
        int x = comm[i] - '0';
        gobl = 10 * gobl + x;
    }

    Node* t = (Node*)malloc(sizeof(Node));
    if (*head == nullptr)
    {
        *head = t;
    }
    else
    {
        Node* c = *head;
        while (c->next)
            c = c->next;
        c->next = t;
    }
    t->next = nullptr;
    t->value = gobl;

}

void middle(Node** head, string comm)
{
    int gobl = 0;
    for (int i = 2;i < comm.length();++i)
    {
        int x = comm[i] - '0';
        gobl = 10 * gobl + x;
    }

    Node* t = (Node*)malloc(sizeof(Node));
    if (*head == nullptr)
    {
        *head = t;
        t->next = nullptr;
    }
    else
    {
        int count=1;
        Node* c = *head;
        while (c->next)
        {
            c = c->next;
            count ++;
        }
        c = *head;
        for (int i = 0; i < (count - 1) / 2;++i)
            c = c->next;
        t->next = c->next;
        c->next = t;
    }
    t->value = gobl;
}

int beg(Node** head)
{
    int goblin = (*head)->value;
    Node* curr = (*head)->next;
    free(*head);
    *head = curr;
    return goblin;
}

int main()
{
    int n;
    string comm;
    cin >> n;
    Node* head = nullptr;

    for (int i = 0;i < n+1;++i)
    {
        getline(cin, comm);
        if (int(comm[0]) == 43)
            end(&head, comm);
        if (int(comm[0])== 42)
            middle(&head, comm);
        if (int(comm[0]) == 45)
            cout << beg(&head) << endl;
    }


    return 0;
}