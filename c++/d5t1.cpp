#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    map<int,int> mp;
    int n1, n2, n3, nums1[100], nums2[100], nums3[100];
    set <int> set1, set2, set3;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
        set1.insert(nums1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
        set2.insert(nums2[i]);
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> nums3[i];
        set3.insert(nums3[i]);
    }
    for (auto elem : set1)
    {
        mp[elem]++;
    }
    for (auto elem : set2)
    {
        mp[elem]++;
    }
    for (auto elem : set3)
    {
        mp[elem]++;
    }
    for (auto num = mp.begin(); num != mp.end(); num++)
    {
        if (num->second >= 2)
        {
            cout << num->first << ' ';
        }
    }
}