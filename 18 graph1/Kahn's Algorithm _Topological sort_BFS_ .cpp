#include <Bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int v, vector<int> adj[])
    {

        vector<int> vis(v, 0);
        stack<int> st;
        vector<int> indeg(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (auto ind : adj[i])
                indeg[ind]++;
        }
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for (auto it : adj[top])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};