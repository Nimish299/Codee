#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
        stack<int> st;
        vector<int> indeg(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            for (auto ind : adj[i])
                indeg[ind]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
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
        if (ans.size() == numCourses)
            return true;
        return false;
    }
};