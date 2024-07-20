#include <Bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int j = 0;
        vector<int> bfs;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            bfs.push_back(n);
            for (auto i : adj[n])
            {
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return bfs;
    }
};