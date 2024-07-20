
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // sort(nums.begin(), nums.end());
        map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int moreNeeded = abs(nums[i] - target);

            if (mp.find(moreNeeded) != mp.end())
            {
                ans.push_back(mp[moreNeeded]);
                ans.push_back(i);
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return ans;
    };
} 

int main()
{

    cout << "cc" << endl;
}
