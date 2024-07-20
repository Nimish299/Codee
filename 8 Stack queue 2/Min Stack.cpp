

#include <bits/stdc++.h>

using namespace std;

class MinStack
{
    stack<pair<int, int>> st;
    int mini;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
        }
        else
        {
            mini = min(st.top().second, val);
        }

        st.push({val, mini});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{

    cout << "cc" << endl;
}
