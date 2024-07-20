
#include <bits/stdc++.h>

using namespace std;
// we are takling 2 counter as there can be maximum 2 element with > n/3
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int t1, t2;
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (c1 == 0 && nums[i] != t2)
            {
                c1 = 1;
                t1 = nums[i];
            }
            else if (c2 == 0 && nums[i] != t1)
            {
                c2 = 1;
                t2 = nums[i];
            }
            else if (nums[i] == t1)
                c1++;
            else if (nums[i] == t2)
                c2++;
            else
            {
                c1--;
                c2--;
            }
        }
        int check1 = 0;
        int check2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == t1)
                check1++;
            if (nums[i] == t2)
                check2++;
        }
        vector<int> v;
        int mid = (int)n / 3 + 1;
        if (check1 >= mid)
            v.push_back(t1);
        if (check2 >= mid)
            v.push_back(t2);

        return v;
    }
};