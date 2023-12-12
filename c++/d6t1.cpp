#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int num;
    struct Node *next;
}node;
node *l1, *l2, *l_link;
int len1 = 0, len2 = 0;

void create_ll();
void insert();//默认对l1操作
void Delete();//默认对l1操作
void print(node *ll, int k);
void Free(node *l, int k);
void link();//默认对l1-l2
void find_place();//默认对l1操作
void find_value();//默认对l1操作

int main()
{
    create_ll();
    print(l1, 1);
    print(l2, 2);

    insert();
    print(l1, 1);

    Delete();
    print(l1, 1);

    find_place();
    find_value();

    link();
    print(l_link, 3);

    Free(l1, 1);
    Free(l2, 2);
    Free(l_link, 3);
}
void create_ll()
{
    cout << "list 1: ";
    int num;
    node *curr;
    while (cin >> num)
    {
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
        len1++;
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
        len2++;
        if (cin.get() == '\n')
        {
            break;
        }
    }
}

void insert()
{
    int num, place;
    while (1)
    {
        printf("insert a num and its place: ");
        scanf("%d%d", &num, &place);
        if (place >= 0 && place <= len1)
        {
            break;
        }
    }
    node *n = (node *)malloc(sizeof(node));
    n->num = num;
    n->next = NULL;
    if (place == 0)
    {
        n->next = l1;
        l1 = n;
    }
    else if (place == len1)
    {
        node *curr = l1;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        node *curr = l1, *tmp = l1;
        for (int i = 0; i < place; i++)
        {
            tmp = curr;
            curr = curr->next;
        }
        tmp->next = n;
        n->next = curr;
    }
    len1++;
}

void Delete()
{
    int place;
    while (1)
    {
        printf("delete a num at place: ");
        scanf("%d", &place);
        if (place >= 0 && place < len1)
        {
            break;
        }
    }
    if (l1 == NULL)
    {
        printf("linked list is empty\n");
    }
    node *curr = l1, *tmp = l1;
    for (int i = 0; i < place; i++)
    {
        tmp = curr;
        curr = curr->next;
    }
    if (!place)
    {
        l1 = l1->next;
        free(curr);
    }
    else
    {
        tmp->next = curr->next;
        free(curr);
    }
    len1--;
}

void print(node *ll, int k)
{
    if (k == 1 || k == 2)
    {
        cout << "the list " << k << " is: ";
    }
    else
    {
        cout << "the linked list is: ";
    }
    for (node *p = ll; p != NULL; p = p->next)
    {
        cout << p->num << ' ';
    }
    cout << endl;
}

void Free(node *l, int k)
{
    node *tmp = l;
    while(l != NULL)
    {
        tmp = l;
        l = l->next;
        free(tmp);
    }
    if (k == 1)
    {
        len1 = 0;
    }
    else if (k == 2)
    {
        len2 = 0;
    }
}

void link()
{
    node *curr, *tmp = l1;
    while (tmp != NULL)
    {
        node *n = (node *)malloc(sizeof(node));
        n->num = tmp->num;
        n->next = NULL;
        if (l_link == NULL)
        {
            l_link = n;
            curr = n;
        }
        else
        {
            curr->next = n;
            curr = curr->next;
        }
        tmp = tmp->next;
    }
    tmp = l2;
    while (tmp != NULL)
    {
        node *n = (node *)malloc(sizeof(node));
        n->num = tmp->num;
        n->next = NULL;
        if (l_link == NULL)
        {
            l_link = n;
            curr = n;
        }
        else
        {
            curr->next = n;
            curr = curr->next;
        }
        tmp = tmp->next;
    }
}

void find_place()
{
    int place;
    while (1)
    {
        printf("find a num at place: ");
        scanf("%d", &place);
        if (place >= 0 && place < len1)
        {
            break;
        }
    }
    node *curr = l1;
    for (int i = 0; i < place; i++)
    {
        curr = curr->next;
    }
    cout << "the num at place " << place << " is " << curr->num << endl;
}

void find_value()
{
    int num;
    printf("find  num: ");
    scanf("%d", &num);
    node *curr = l1;
    int place = 0, f = 0;
    while (curr != NULL)
    {
        if (curr->num == num)
        {
            cout << "the order is: " << place <<endl;
            f = 1;
        }
        place++;
        curr = curr->next;
    }
    if (!f)
    {
        cout << "the num doesn't exist" << endl;
    }
}