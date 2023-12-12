#include <bits/stdc++.h>
using namespace std;

typedef struct N
{
    int data;
    struct N *nxt;
}node;
node *head, *head_reverse;

void create();
void reverse();

int main()
{
    create();
    reverse();
    node *curr = head_reverse;
    while (curr != NULL)
    {
        cout << curr->data << ' ';
        curr = curr->nxt;
    }
}

void create()
{
    cout << "create a list" << endl << "nums: ";
    int num;
    node *curr;
    while (cin >> num)
    {
        node *n = (node*)malloc(sizeof(node));
        n->data = num;
        n->nxt = NULL;
        if (head == NULL)
        {
            head = n;
            curr = head;
        }
        else
        {
            curr->nxt = n;
            curr = curr->nxt;
        }
        if (cin.get() == '\n')
        {
            break;
        }
    }
}

void reverse()
{
    stack<int> q;
    node *curr = head;
    while (curr != NULL)
    {
        q.push(curr->data);
        curr = curr->nxt;
    }
    while (!q.empty())
    {
        node *n = (node*)malloc(sizeof(node));
        n->data = q.top();
        q.pop();
        n->nxt = NULL;
        if (head_reverse == NULL)
        {
            head_reverse = n;
            curr = head_reverse;
        }
        else
        {
            curr->nxt = n;
            curr = curr->nxt;
        }
    }
}