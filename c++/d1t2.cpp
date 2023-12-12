#include <bits/stdc++.h>
using namespace std;
int ban[7] = {0};
int main()
{
    char s[100];
    cin >> s;
    int l = strlen(s), sum = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 'M')
        {
            sum += 1000;
            if (i && s[i - 1] == 'C')
            {
                sum -= 200;
            }
        }
        else if (s[i] == 'D')
        {
            sum += 500;
            if (i && s[i - 1] == 'C')
            {
                sum -= 200;
            }
        }
        else if (s[i] == 'C')
        {
            sum += 100;
            if (i && s[i - 1] == 'X')
            {
                sum -= 20;
            }
        }
        else if (s[i] == 'L')
        {
            sum +=50;
            if (i && s[i - 1] == 'X')
            {
                sum -= 20;
            }
        }
        else if (s[i] == 'X')
        {
            sum += 10;
            if (i && s[i - 1] == 'I')
            {
                sum -= 2;
            }
        }
        else if (s[i] == 'V')
        {
            sum += 5;
            if (i && s[i - 1] == 'I')
            {
                sum -= 2;
            }
        }
        else if (s[i] == 'I')
        {
            sum += 1;
        }
    }
    cout << sum;
}