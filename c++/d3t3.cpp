#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int l = s.size(), max = 0;
    stack <char> q;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(')
        {
            q.push('(');
        }
        else if (s[i] == ')')
        {
            int size = q.size();
            if (max < size)
            {
                max = size;
            }
            q.pop();
        }
    }
    cout << max;
}