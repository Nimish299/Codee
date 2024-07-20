
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int m = nums.size();
        int sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < m; i++)
        {
            sum += nums[i];
            maxi = max(sum, maxi);
            if (sum < 0)
            {
                // max = sum;
                sum = 0;
            }
        }
        return maxi;
    }
};