
#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int mid = nums.size() / 2;
//         return (nums[mid])
//     }
// };

// voting algo
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int t = nums[0];
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == t)
                c++;
            else
                c--;

            if (c == 0)
            {
                c = 1;
                t = nums[i];
            }
        }
        int check = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == t)
                check++;
        }
        if (check > n / 2)
            return t;
        else
            return -1;
    }
};