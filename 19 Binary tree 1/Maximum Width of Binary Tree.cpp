
#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int s = q.size();
            int min = q.front().second; // Minimum index at the current level
            int first, last;

            for (int i = 0; i < s; i++)
            {
                int cur_id = q.front().second - min; // Normalize current id
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur_id;
                if (i == s - 1)
                    last = cur_id;

                if (node->left)
                    q.push({node->left, 2 * cur_id});
                if (node->right)
                    q.push({node->right, 2 * cur_id + 1});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};
int main()
{

    cout << "cc" << endl;
}
