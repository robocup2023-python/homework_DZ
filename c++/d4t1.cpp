#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void reverse(string& s);

int main()
{
    ifstream input;
    input.open("input_d4t1.txt");
    string s;
    getline(input, s);
    reverse(s);
}

void reverse(string& s)
{
    int l = s.size();
    char tmp;
    for (int i = 0; i < l / 2; i++)
    {
        tmp = s[i];
        s[i] = s[l - 1 - i];
        s[l - 1 - i] = tmp;
    }
    ofstream output;
    output.open("output_d4t1.txt");
    output << s;
    cout << "success!";
}