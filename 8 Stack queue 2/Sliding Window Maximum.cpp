
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++)
        {

            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    int k = 4;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << endl;
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}