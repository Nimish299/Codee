
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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                // No left child, visit this node and move to the right child
                v.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                // Find the inorder predecessor of cur
                TreeNode *prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    // Establish a temporary link from predecessor to current node
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    // Remove the temporary link and visit the current node
                    prev->right = NULL;
                    v.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return v;
    }
};
int main()
{

    cout << "cc" << endl;
}
