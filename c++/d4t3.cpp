#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int l = s.size();
    int i = 0, j = l - 1;
    while (i < j)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if ((s[j] >= 'a' && s[j] <= 'z') || ((s[j] >= 'A' && s[j] <= 'Z')))
            {
                cout << "false";
                return 0;
            }
            else if (s[j] >= '0' && s[j] <= '9')
            {
                if (s[i] != s[j])
                {
                    cout << "false";
                    return 0;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            else
            {
                j--;
            }
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                cout << "false";
                return 0;
            }
            else if ((s[j] >= 'a' && s[j] <= 'z') || ((s[j] >= 'A' && s[j] <= 'Z')))
            {
                if (s[i] != tolower(s[j]))
                {
                    cout << "false";
                    return 0;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            else
            {
                j--;
            }
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                cout << "false";
                return 0;
            }
            else if ((s[j] >= 'a' && s[j] <= 'z') || ((s[j] >= 'A' && s[j] <= 'Z')))
            {
                if (s[i] != toupper(s[j]))
                {
                    cout << "false";
                    return 0;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
    cout << "true";
}