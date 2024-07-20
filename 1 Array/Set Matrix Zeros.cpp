
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
                // if (rows[i] == 1 ||x` cols[j] == 1)
                //     continue;

                if (matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        // cout << "row";
        // for (int i = 0; i < m; ++i)
        // {
        //     cout << rows[i];
        // }
        // cout << endl;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (rows[i] == 1 || cols[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
};
int main()
{
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
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
