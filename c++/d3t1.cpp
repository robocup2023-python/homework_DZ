#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nums[1000];
    int n, k, pos = -1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i])
        {
            if(pos != -1)
            {
                if (i - pos - 1 < k)
                {
                    cout << "false";
                    return 0;
                }
            }
            pos = i;
        }
    }
    cout << "true";
}