#include <Bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> vis(v, -1);

        for (int start = 0; start < v; ++start)
        {
            if (vis[start] == -1)
            {
                queue<int> q;
                q.push(start);
                vis[start] = 0;

                while (!q.empty())
                {
                    int n = q.front();
                    q.pop();

                    for (auto i : graph[n])
                    {
                        if (vis[i] == -1)
                        {
                            q.push(i);
                            vis[i] = !vis[n];
                        }
                        else if (vis[i] == vis[n])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
