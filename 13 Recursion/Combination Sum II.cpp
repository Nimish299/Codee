
#include <bits/stdc++.h>

using namespace std;
// class Solution
// {

// public:

// use set as unique

//     void sum(int i, int target, vector<int> &candidates, set<vector<int>> &ans, vector<int> &ds)
//     {
//         if (i == candidates.size())
//         {
//             if (target == 0)
//             {
//                 ans.insert(ds);
//             }
//             return;
//         }
//         if (candidates[i] <= target)
//         {
//             ds.push_back(candidates[i]);

//             sum(i + 1, target - candidates[i], candidates, ans, ds);
//             ds.pop_back();
//         }
//         sum(i + 1, target, candidates, ans, ds);
//     }
//     vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
//     {
//         set<vector<int>> ans;
//         vector<int> ds;
//         sort(candidates.begin(), candidates.end());
//         sum(0, target, candidates, ans, ds);
//         vector<vector<int>> aans(ans.begin(), ans.end());
//         return aans;
//     }
// };

class Solution
{
public:
    void sum(int i, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int j = i; j < candidates.size(); j++)
        {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;
            ds.push_back(candidates[j]);
            sum(j + 1, target - candidates[j], candidates, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
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
