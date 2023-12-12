#include <bits/stdc++.h>
using namespace std;

int check(int num);

int main()
{
    int n, cnt = 0;
    cin >> n;
    if (n == 0 || n == 1 || n == 2)
    {
        cout << 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (check(i))
            {
                cnt++;
            }
        }
        cout << cnt;
    }
}

int check(int num)
{
    int k = (int)sqrt(num);
    for (int i = 2; i <= k; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}