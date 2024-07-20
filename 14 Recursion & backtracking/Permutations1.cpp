
#include <bits/stdc++.h>

using namespace std;
// class Solution
// {
// public:
//     void com(vector<int> &ds, vector<int> nums, vector<vector<int>> &ans, int freq[])
//     {
//         if (ds.size() == nums.size())
//         {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (!freq[i])
//             {
//                 ds.push_back(nums[i]);
//                 freq[i] = 1;
//                 com(ds, nums, ans, freq);
//                 freq[i] = 0;
//                 ds.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<int> ds;
//         vector<vector<int>> ans;
//         int n = nums.size();
//         int freq[n] = {0};
//         for (int i = 0; i < nums.size(); i++)
//         {
//             freq[i] = 0;
//         }

//         com(ds, nums, ans, freq);
//         return ans;
//     }
// };

class Solution
{
public:
    void com(int ind, vector<int> nums, vector<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            com(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        com(0, nums, ans);
        return ans;
    }
};
int main()
{

    cout << "cc" << endl;
    int a, v;
    cin >> a;
    cin >> v;
    int c;
    cin >> c;
    if (c == 1)
        cout << a + v;
    else
        cout << a - v;
}
