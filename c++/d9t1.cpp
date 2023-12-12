#include <bits/stdc++.h>
using namespace std;

typedef struct N
{
    int data;
    struct N *nxt;
}node;
node *head;

void create();
bool check();

int main()
{
    create();
    if (check())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
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

bool check()
{
    node *curr = head;
    int a[1000] = {0}, cnt = 0;
    while (curr != NULL)
    {
        a[cnt] = curr->data;
        cnt++;
        curr = curr->nxt;
    }
    for (int i = 0; i < cnt / 2; i++)
    {
        if (a[i] != a[cnt - i - 1])
        {
            return false;
        }
    }
    return true;
}
