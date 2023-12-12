#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int a[500] = {0};
char s[550];
int main()
{
    gets(s);
    int l = strlen(s), k = 0, sum = 0, max = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <='9')
        {
            sum += (s[i] - '0') * pow(10, k);
            k++;
        }
        else if (s[i] == '[' || s[i] == ',')
        {
            k = 0;
            a[sum] = 1;
            if (max < sum)
            {
                max = sum;
            }
            sum = 0;
            if (s[i] == '[')
            {
                break;
            }
        }
    }
    for (int i = 0; i <= max; i++)
    {
        if (!a[i])
        {
            cout << i;
            return 0;
        }
    }
    cout << max + 1;
}