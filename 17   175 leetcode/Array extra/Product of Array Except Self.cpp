
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Calculate left product prefix and store in ans
        int left = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = left;
            left *= nums[i];
        }

        // Calculate right product prefix and multiply with ans
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};
int main()
{
    vector<int> nums = {3, 4, 6, 1, 2};
    vector<int> ans;
    Solution Solution;
    ans = Solution.productExceptSelf(nums);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}

/*

 int n = nums.size();
        vector<int> ans(n, 1);  // Initialize ans with size n and all values as 1
        vector<int> leftproprefix(n, 1);
        vector<int> rightproprefix(n, 1);

        // Compute left product prefix
        for (int i = 1; i < n; i++)
        {
            leftproprefix[i] = leftproprefix[i - 1] * nums[i - 1];
        }

        // Compute right product prefix
        for (int i = n - 2; i >= 0; i--)
        {
            rightproprefix[i] = rightproprefix[i + 1] * nums[i + 1];
        }

        // Compute the answer by multiplying left and right prefix products
        for (int i = 0; i < n; i++)
        {
            ans[i] = leftproprefix[i] * rightproprefix[i];
        }

        return ans;
*/