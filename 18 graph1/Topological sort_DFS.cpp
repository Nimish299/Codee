#include <Bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    void dfs(int ind, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {

        vis[ind] = 1;

        for (auto i : adj[ind])
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }
        st.push(ind);
    }
    vector<int> topoSort(int v, vector<int> adj[])
    {

        vector<int> vis(v, 0);
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }
        vector<int> ans;

        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }
        return ans;
    }
};