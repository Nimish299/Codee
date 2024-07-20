#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (!kArrays[i].empty())
        {
            pq.push({kArrays[i][0], i});
            kArrays[i].erase(kArrays[i].begin());
        }
    }

    while (!pq.empty())
    {
        pair<int, int> t = pq.top();
        pq.pop();
        ans.push_back(t.first);
        if (!kArrays[t.second].empty())
        {
            pq.push({kArrays[t.second][0], t.second});
            kArrays[t.second].erase(kArrays[t.second].begin());
        }
    }
    return ans;
}
