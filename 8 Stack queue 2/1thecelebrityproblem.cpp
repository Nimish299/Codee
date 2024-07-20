
#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
bool knows(int a, int b)
{
    return true;
}
int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(a, b))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    if (st.empty())
        return -1;
    int t = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i != t && (!knows(i, t) || knows(t, i)))
        {
            return -1;
        }
    }

    return t;
}
int main()
{

    cout << "cc" << endl;
    int a, v;
    cin >> a;
    cin >> v;
    int c;
    cin >> c;
    if (c == 1)
        cout << a + v;
    else
        cout << a - v;
}
