#include <bits/stdc++.h>

using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    vector<int> ans;
    int n = A.size();
    stack<int> st;
    
    for (int i = 0; i < n; i++)
    {
        // Pop elements from the stack if they are greater than or equal to A[i]
        while (!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }
        
        // If stack is empty, no smaller element exists, else top of stack is the previous smaller element
        if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        
        // Push the current element to the stack
        st.push(A[i]);
    }
    
    return ans;
}

int main()
{
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> Ans = prevSmaller(A);
    
    for (int x : Ans)
        cout << x << " ";
        
    return 0;
}
