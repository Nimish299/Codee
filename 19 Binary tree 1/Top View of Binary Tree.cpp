
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {

            auto p = q.front();
            q.pop();

            Node *node = p.first;

            int y = p.second;
            if (mp.find(y) == mp.end())
                mp[y] = (node->data);

            if (node->left)
            {

                q.push({node->left, y - 1});
            }
            if (node->right)
            {
                q.push({node->right, y + 1});
            }
        }
        for (auto p : mp)
        {
            ans.push_back(p.second);
        }
        return ans;
        // Your code here
    }
};
int main()
{

    cout << "cc" << endl;
}
