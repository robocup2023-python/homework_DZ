#include <bits/stdc++.h>
using namespace std;

int a[100] = {0}, cnt = 0;

void check(int num);
int count(int num);

int main()
{
    int n;
    cin >> n;
    check(n);
}

void check(int num)
{
    for (int i = 0; i < cnt; i++)
    {
        if (num == a[i])
        {
            cout << "false";
            return;
        }
    }
    if (num == 1)
    {
        cout << "true";
        return;
    }
    a[cnt] = num;
    cnt++;
    check(count(num));
}

int count(int num)
{
    int ans = 0;
    while (num)
    {
        int k = num % 10;
        ans += k * k;
        num /= 10;
    }
    return ans;
}