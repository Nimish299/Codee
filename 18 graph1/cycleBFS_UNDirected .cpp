//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    bool bfsOfGraph(int src, vector<int> &vis, vector<int> adj[])
    {

        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = 1;
        int j = 0;

        while (!q.empty())
        {
            int n = q.front().first;
            int p = q.front().second;
            q.pop();

            for (auto i : adj[n])
            {
                if (!vis[i])
                {
                    q.push({i, n});
                    vis[i] = 1;
                }
                else if (p != i)
                    return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && bfsOfGraph(i, vis, adj))

                return true;
        }

        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends