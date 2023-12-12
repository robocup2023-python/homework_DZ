#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void func(string s);
FILE* File = fopen("output_d4t2.txt", "w");

int main()
{
    string s;
    ifstream input;
    input.open("input_d4t2.txt");
    while(getline(input,s))
    {                    
        func(s);
    }
}

void func(string s)
{
    stack<char> q;
    int l = s.size();
    for (int i = 0; i < l; i++)
    {
        if (!q.empty())
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (q.top() == toupper(s[i]))
                {
                    q.pop();
                    continue;
                }
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                if (q.top() == tolower(s[i]))
                {
                    q.pop();
                    continue;
                }
            }
        }
        q.push(s[i]);
    }
    stack<char>qq;
    while (!q.empty())
    {
        qq.push(q.top());
        q.pop();
    }
    string ans = "";
    while (!qq.empty())
    {
        ans += qq.top();
        qq.pop();
    }
    fprintf(File,"%s\n",s.c_str()); // 只能输出char数组，与string不一样，在string后加上.c_str()即可
}