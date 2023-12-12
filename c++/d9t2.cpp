#include <bits/stdc++.h>
using namespace std;

class node
{
private:
    node *head;
public:
    int val;
    node *next;
    node()
    {
        head = NULL;
        next = NULL;
        val = 0;
    }
    int get(int index)
    {
        node *curr = head;
        if (index < 0)
        {
            return -1;
        }
        int cnt = 0;
        node *p = NULL;
        while (curr != NULL)
        {
            if (cnt == index)
            {
                p = curr;
                break;
            }
            cnt++;
            curr = curr->next;
        }
        if (p == NULL)
        {
            return -1;
        }
        return p->val;
    }
    void addAtHead(int val)
    {
        node *n = new node();
        n->val = val;
        n->next = head;
        head = n;
    }
    void addAtTail(int val)
    {
        node *curr = head;
        if (head == NULL)
        {
            node *n = new node();
            n->val = val;
            n->next = NULL;
            head = n;
            return;
        }
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        node *n = new node();
        n->val = val;
        n->next = NULL;
        curr->next = n;
    }
    void addAtIndex(int index, int val)
    {
        if (index < 0)
        {
            return;
        }
        else if (index == 0)
        {
            addAtHead(val);
            return;
        }
        int cnt = 0;
        node *curr = head, *prev;
        while (curr != NULL)
        {
            if (cnt == index)
            {
                break;
            }
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        if (cnt != index)
        {
            return;
        }
        if (curr == NULL)
        {
            addAtTail(val);
            return;
        }
        else
        {
            node *n = new node();
            n->val = val;
            n->next = NULL;
            prev->next = n;
            n->next = curr;
            return;
        }
    }
    void deleteAtIndex(int index)
    {
        if (index < 0)
        {
            return;
        }
        node *curr = head, *prev;
        int cnt = 0;
        while (curr != NULL)
        {
            if (cnt == index)
            {
                break;
            }
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            return;
        }
        if (!index)
        {
            prev = head;
            head = head->next;
            delete prev;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
    }
    void output()
    {
        node *curr = head;
        while (curr != NULL)
        {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    node *n = new node();
    n->addAtHead(1);
    n->output();
    n->addAtTail(3);
    n->output();
    n->addAtIndex(1, 2); // 链表变为 1->2->3
    n->output();
    cout << n->get(1) << endl; // 返回 2
    n->deleteAtIndex(1); // 现在，链表变为 1->3
    n->output();
    cout << n->get(1);
}
