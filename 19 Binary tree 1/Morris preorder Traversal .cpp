
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> getPreOrderTraversal(TreeNode *root)
    {
        vector<int> v;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                // No left child, visit this node and move to the right child
                v.push_back(cur->data);
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
                    v.push_back(cur->data);
                    cur = cur->left;
                }
                else
                {
                    // Remove the temporary link and visit the current node
                    prev->right = NULL;

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
