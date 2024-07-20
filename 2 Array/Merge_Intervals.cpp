#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        // return intervals;
        vector<vector<int>> merge;
        int s = intervals[0][0];
        int e = intervals[0][1];
        // cout<<s<<e<<endl
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= e)
            {
                e = max(e, intervals[i][1]);
            }
            else
            {
                merge.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        // Add the last interval
        merge.push_back({s, e});

        return merge;
    }
};

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution sol;
    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged intervals: " << endl;
    for (const auto &interval : mergedIntervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}