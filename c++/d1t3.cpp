#include <bits/stdc++.h>
using namespace std;

int find(int sum);
int ans[100] = {0};
int main()
{
    int n;
    cin >> n;
    cout << find(n);
}

int find(int sum)
{
    if (sum == 0)
    {
        return ans[sum] = 1;
    }
    else if (sum < 0)
    {
        return 0;
    }
    else if (sum == 1)
    {
        return ans[sum] = 1;
    }
    else
    {
        int a1 = 0, a2 = 0;
        if (ans[sum - 2])
        {
            a2 = 1;
        }
        else if (ans[sum - 1])
        {
            a1 = 1;
        }
        if (a1 && a2)
        {
            return ans[sum - 1] + ans[sum - 2];
        }
        else if (a1 && !a2)
        {
            return ans[sum - 1] + (ans[sum - 2] = find(sum - 2));
        }
        else if (!a1 && a2)
        {
            return ans[sum - 2] + (ans[sum - 1] = find(sum - 1));
        }
        else
        {
            return (ans[sum - 2] = find(sum - 2)) + (ans[sum - 1] = find(sum - 1));
        }
    }
}
