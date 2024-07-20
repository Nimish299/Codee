
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void subset(int ind, vector<int> &ans, vector<int> &arr, vector<vector<int>> &subsetsum)
    {

        subsetsum.push_back(ans);
        for (int i = ind; i < arr.size(); i++)
        {
            if (i != ind && arr[i] == arr[i - 1])
                continue;
            ans.push_back(arr[i]);
            subset(i + 1, ans, arr, subsetsum);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> ans;
        vector<vector<int>> subsetsum;
        sort(nums.begin(), nums.end());
        subset(0, ans, nums, subsetsum);
        return subsetsum;
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
