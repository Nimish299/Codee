
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
void traverse(Node *root, int level, vector<int> &v)
{
    // (base case for recursion), return
    if (root == nullptr)
    {
        return;
    }
    if (v.size() == level)
        v.push_back(root->data);
    traverse(root->left, level + 1, v);

    traverse(root->right, level + 1, v);
}
// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> v;
    traverse(root, 0, v);
    return v;
}

int main()
{

    cout << "cc" << endl;
}
