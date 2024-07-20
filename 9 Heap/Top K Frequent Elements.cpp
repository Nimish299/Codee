#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> maxHeap;
        for (auto &pair : mp)
        {
            maxHeap.push({pair.second, pair.first});
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};