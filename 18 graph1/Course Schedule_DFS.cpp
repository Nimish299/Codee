#include <Bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool dfst(int n, vector<vector<int>> &adj, vector<int> &DFS_vis, vector<int> &vis)
    {
        vis[n] = 1;
        DFS_vis[n] = 1;
        for (auto i : adj[n])
        {
            if (!vis[i])
            {
                if (dfst(i, adj, DFS_vis, vis))
                    return true;
            }
            else if (DFS_vis[i])
            {
                return true; // Cycle detected
            }
        }
        DFS_vis[n] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> adj(numCourses);

        for (auto i : prerequisites)
        {
            int req = i[1];
            int cou = i[0];
            adj[req].push_back(cou);
        }
        vector<int> vis(numCourses, 0);
        vector<int> DFS_vis(numCourses, 0);
        vector<int> dfs;

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i] && dfst(i, adj, DFS_vis, vis))
                return false;
        }

        return true;
    }
};