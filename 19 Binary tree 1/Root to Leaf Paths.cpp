
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    void traverse(Node *root, vector<vector<int>> &ans, vector<int> &ds)
    {
        // (base case for recursion), return
        if (root == nullptr)
        {
            ans.push_back(ds);
        }
        ds.push_back(root->data);
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(ds);
        }
        else
        {
            if (root->left)
            {
                traverse(root->left, ans, ds);
            }
            if (root->right)
            {
                traverse(root->right, ans, ds);
            }
        }

        ds.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        traverse(root, ans, ds);
        return ans;
    }
};

int main()
{

    cout << "cc" << endl;
}
