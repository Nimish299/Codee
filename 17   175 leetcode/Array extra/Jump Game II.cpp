
#include <bits/stdc++.h>
using namespace std;
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int j = 0, l = 0, r = 0;

        while (r < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = l; i <= r; i++)
            { // corrected condition to <=
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            j++;
        }
        return j;
    }
};

// DPPP
//  class Solution
//  {
//  public:
//      int fun(int ind, int jump, vector<int> &nums, vector<vector<int>> &dp)
//      {
//          if (ind >= nums.size() - 1)
//              return jump;
//          if (dp[ind][jump] != -1)
//              return dp[ind][jump];
//          int mini = INT_MAX;
//          for (int i = 1; i <= nums[ind]; i++)
//          {
//              mini = min(mini, fun(ind + i, jump + 1, nums, dp));
//          }
//          dp[ind][jump] = mini;
//          return mini;
//      }
//      int jump(vector<int> &nums)
//      {
//          int n = nums.size();
//          vector<vector<int>> dp(n, vector<int>(n, -1));
//          return fun(0, 0, nums, dp);
//      }
//  };
int main()
{

    cout << "cc" << endl;
}
