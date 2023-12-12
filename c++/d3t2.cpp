#include <bits/stdc++.h>
#include <map>
using namespace std;

vector<vector<string>> paths;
map <string, int> check;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        vector<string>path;
        cin >> m;
        getchar();
        for (int j = 0; j < m; j++)
        {
            string s;
            getline(cin, s);
            path.push_back(s);
            if (j == m - 1)
            {
                check[s] = 1;
            }
        }
        paths.push_back(path);
    }
    for (int i = 0; i < n; i++)
    {
        int m = paths[i].size();
        for (int j = 0; j < m; j++)
        {
            if (j != m - 1)
            {
                if (check.count(paths[i][j]))
                {
                    check.erase(paths[i][j]);
                }
            }
        }
    }
    cout << "The destination is: " << check.begin()->first;
}