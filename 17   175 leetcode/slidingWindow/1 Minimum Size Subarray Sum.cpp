#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0;
        int start = 0;

        for (int end = 0; end < n; ++end)
        {
            sum += nums[end];

            while (sum >= target)
            {
                minLength = min(minLength, end - start + 1);
                sum -= nums[start++];
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};

int main()
{
    int t = 11;
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution S;
    cout << S.minSubArrayLen(t, nums);
}