#include <bits/stdc++.h>
using namespace std;

typedef struct N
{
    int data;
    struct N *nxt;
}node;
node *head1, *head2, *head;

void create();
void findIntersect();

int main()
{
    create();
    findIntersect();
    if (head)
    {
        cout << head << ' ' << head->data;
    }
    else
    {
        cout << "链表不相交";
    }
}

void create()
{
    cout << "create list1(specific)" << endl << "nums: ";
    int num;
    node *curr1, *curr2;
    while (cin >> num)
    {
        node *n = (node*)malloc(sizeof(node));
        n->data = num;
        n->nxt = NULL;
        if (head1 == NULL)
        {
            head1 = n;
            curr1 = head1;
        }
        else
        {
            curr1->nxt = n;
            curr1 = curr1->nxt;
        }
        if (cin.get() == '\n')
        {
            break;
        }
    }
    cout << "create list2(specific)" << endl << "nums: ";
    while (cin >> num)
    {
        node *n = (node*)malloc(sizeof(node));
        n->data = num;
        n->nxt = NULL;
        if (head2 == NULL)
        {
            head2 = n;
            curr2 = head2;
        }
        else
        {
            curr2->nxt = n;
            curr2 = curr2->nxt;
        }
        if (cin.get() == '\n')
        {
            break;
        }
    }
    int cnt = 0, intersectsum;
    cout << "create list(intersect)" << endl << "intersectsum: ";
    cin >> intersectsum;
    if (!intersectsum)
    {
        return;
    }
    cout << "nums: ";
    while (cin >> num)
    {
        node *n = (node*)malloc(sizeof(node));
        n->data = num;
        n->nxt = NULL;
        if (!cnt)
        {
            curr1->nxt = n;
            curr2->nxt = n;
            curr1 = curr1->nxt;
        }
        else
        {
            curr1->nxt = n;
            curr1 = curr1->nxt;
        }
        cnt++;
        if (cin.get() == '\n')
        {
            break;
        }
    }
}

void findIntersect()
{
    set <node*> myset;
    node *curr1 = head1, *curr2 = head2;
    while (curr1 != NULL)
    {
        myset.insert(curr1);
        curr1 = curr1->nxt;
    }
    while (curr2 != NULL)
    {
        if (myset.count(curr2))
        {
            head = curr2;
            return;
        }
        curr2 = curr2->nxt;
    }
}