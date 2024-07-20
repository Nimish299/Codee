
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (rows[i] == 0 || cols[j] == 0)
                    continue;

                if (matrix[i][j] == 0)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (rows[i] == 0 || cols[j] == 0)
                    matrix[i][j] == 0
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    sol.setZeroes(matrix);

    // Print the modified matrix
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
