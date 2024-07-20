#include <Bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool dfst(int n, int color, vector<vector<int>> &graph, vector<int> &vis)
    {
        vis[n] = color;
        // dfs.push_back(n);
        for (auto i : graph[n])
        {
            if (vis[i] == -1)
            {
                if (!dfst(i, !color, graph, vis))
                {
                    return false;
                }
            }
            else if (vis[i] == color)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> vis(v, -1);

        for (int start = 0; start < v; ++start)
        {
            if (vis[start] == -1)
            {
                if (dfst(start, 0, graph, vis) == false)

                    return false;
            }
        }
        return true;
    }
};