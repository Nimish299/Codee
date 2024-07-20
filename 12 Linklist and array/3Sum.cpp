
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // Avoid duplicates for the current element
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // Avoid duplicates for the second element
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    // Avoid duplicates for the third element
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
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
