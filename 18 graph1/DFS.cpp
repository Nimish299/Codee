//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfst(int n, vector<int> adj[], vector<int> &dfs, vector<int> &vis)
    {
        vis[n] = 1;
        dfs.push_back(n);
        for (auto i : adj[n])
        {
            if (!vis[i])
                dfst(i, adj, dfs, vis);
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> dfs;

        dfst(0, adj, dfs, vis);
        return dfs;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends