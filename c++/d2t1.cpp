#include <bits/stdc++.h>
using namespace std;

void check(int num);

int main()
{
    int n;
    cin >> n;
    check(n);
}

void check(int num)
{
    if (num <= 0)
    {
        cout << "false";
    }
    while (num % 2 == 0)
    {
        num /= 2;
    }
    while (num % 3 == 0)
    {
        num /= 3;
    }
    while (num % 5 == 0)
    {
        num /= 5;
    }
    if (num == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}