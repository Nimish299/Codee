
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
 int solve(int ind, vector<int> &nums, vector<int> &dp)
    {

        if (ind == 0)
        {
            return nums[0];
        }
        if (ind < 0)
            return 0;

        int pick = nums[ind] + solve(ind - 2, nums,dp);
        int NOpick = solve(ind - 1, nums,dp);

        return dp[ind] = max(pick, NOpick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0; // Edge case: No houses
        if (n == 1)
            return nums[0]; // Edge case: Only one house
                            // Case 1: Exclude the first house
        vector<int> excludeFirst(nums.begin() + 1, nums.end());
        vector<int> dp(n - 1, -1);
        int excludeFirstResult = solve(n - 2, excludeFirst, dp);
        vector<int> dp2(n - 1, -1);
        // Case 2: Exclude the last house
        vector<int> excludeLast(nums.begin(), nums.end() - 1);
        int excludeLastResult = solve(n - 2, excludeLast, dp2);

        return max(excludeFirstResult, excludeLastResult);
    }
};