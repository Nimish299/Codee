
#include <bits/stdc++.h>

using namespace std;
class Solution
{

public:
    void sum(int i, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (i == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (candidates[i] <= target)
        {
            ds.push_back(candidates[i]);

            sum(i, target - candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
        sum(i + 1, target, candidates, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sum(0, target, candidates, ans, ds);
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
