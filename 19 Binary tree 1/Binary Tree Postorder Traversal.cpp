
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
    void traverse(TreeNode *root, vector<int> &v)
    {
        // (base case for recursion), return
        if (root == nullptr)
        {
            return;
        }
       
        traverse(root->left, v);

        traverse(root->right, v);
         v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        traverse(root, v);
        return v;
    }
};
int main()
{

    cout << "cc" << endl;
}
