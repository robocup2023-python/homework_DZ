#include <bits/stdc++.h>
using namespace std;

typedef struct N
{
    int data;
    int id;
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
    cout << "create a list" << endl << "pos: ";
    int num, pos, cnt = 0;
    cin >> pos;
    cout << "nums: ";
    node *curr, *p;
    while (cin >> num)
    {
        node *n = (node*)malloc(sizeof(node));
        n->data = num;
        n->nxt = NULL;
        n->id = cnt;
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
        if (cnt == pos)
        {
            p = curr; 
        }
        cnt++;
        if (cin.get() == '\n')
        {
            break;
        }
    }
    if (pos != -1)
    {
        curr->nxt = p;
    }
}

// bool check() //diy struct
// {
//     node *curr = head;
//     int max = 0;
//     while (curr != NULL)
//     {
//         if (max >= curr->id)
//         {
//             return true;
//         }
//         max++;
//         curr = curr->nxt;
//     }
//     return false;
// }

bool check()
{
    set <node*> myset;
    node *curr = head;
    while (curr != NULL)
    {
        if (myset.count(curr))
        {
            return true;
        }
        myset.insert(curr);
        curr = curr->nxt;
    }
    return false;
}