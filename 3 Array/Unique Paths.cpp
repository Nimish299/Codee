
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int count(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == (n - 1) || j == (m - 1))
        {
            return 1;
        }
        if (dp[i][j] != 0)
        {
            return dp[i][j];
        }
        dp[i][j] = count(i, j + 1, m, n, dp) + count(i + 1, j, m, n, dp);
        return dp[i][j];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        return count(0, 0, m, n, dp);
    }
};
int main()
{
    Solution solution;
    int m = 3;
    int n = 2;
    cout << "Number of unique paths for a " << m << "x" << n << " grid: " << solution.uniquePaths(m, n) << endl;

    // Test with another grid size
    m = 7;
    n = 3;
    cout << "Number of unique paths for a " << m << "x" << n << " grid: " << solution.uniquePaths(m, n) << endl;

    return 0;
}