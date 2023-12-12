#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int num;
    struct Node *next;
}node;
node *l1, *l2;

void create_ll();
void merge();

int main()
{
    create_ll();
    merge();
}

void create_ll()
{
    cout << "list 1: ";
    int num;
    node *curr;
    while (cin >> num)
    {
        cout << 1<<endl;
        node *n = (node *)malloc(sizeof(node));
        n->num = num;
        n->next = NULL;
        if (l1 == NULL)
        {
            l1 = n;
            curr = n;
        }
        else
        {
            curr->next = n;
            curr = curr->next;
        }
        if (cin.get() == '\n')
        {
            break;
        }
    }
    cout << "list 2: ";
    while (cin >> num)
    {
        node *n = (node *)malloc(sizeof(node));
        n->num = num;
        n->next = NULL;
        if (l2 == NULL)
        {
            l2 = n;
            curr = n;
        }
        else
        {
            curr->next = n;
            curr = curr->next;
        }
        if (cin.get() == '\n')
        {
            break;
        }
    }
}

void merge()
{
    node *i = l1, *j = l2, *prev = l1;
    if (i->num > j->num)
    {
        node *n = (node*)malloc(sizeof(node));
        n->num = j->num;
        n->next = NULL;
        n->next = l1;
        l1 = n;
        i = l1;
        j = j->next;
        prev = l1;
    }
    while (i != NULL && j != NULL)
    {
        if (i->num > j->num)
        {
            node *n = (node*)malloc(sizeof(node));
            n->num = j->num;
            n->next = NULL;
            prev->next = n;
            n->next = i;
            j = j->next;
            prev = n;
        }
        else
        {
            prev = i;
            i = i->next;
        }
    }
    if (i == NULL && j != NULL)
    {
        prev->next = j;
    }
    cout << "the merged list is: ";
    for (node *p = l1; p != NULL; p = p->next)
    {
        cout << p->num << ' ';
    }
    cout << endl;
}