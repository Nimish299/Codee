#include <bits/stdc++.h>

using namespace std;

vector<int> maxMinWindow(vector<int> a, int n)
{
    vector<int> rs(n);
    vector<int> ls(n);
    stack<int> st;

    // Find previous smaller elements
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty())
            ls[i] = -1;
        else
            ls[i] = st.top();
        st.push(i);
    }

    // Clear stack for reuse
    while (!st.empty())
    {
        st.pop();
    }

    // Find next smaller elements
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty())
            rs[i] = n;
        else
            rs[i] = st.top();
        st.push(i);
    }

    vector<int> len(n, INT_MIN);

    // Calculate the maximum of minimums for each window size
    for (int i = 0; i < n; i++)
    {
        int length = rs[i] - ls[i] - 1;
        len[length - 1] = max(len[length - 1], a[i]);
    }

    // Fill in the remaining values to ensure maximum values carry over to smaller window sizes
    for (int i = n - 2; i >= 0; i--)
    {
        len[i] = max(len[i], len[i + 1]);
    }

    return len;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> result = maxMinWindow(a, n);

    cout << "Result: ";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n)
{  vector<int> ans;
    for (int k = 1; k <= a.size(); k++)
    {
        int maxi = INT16_MIN;
        deque<int> dq;
        for (int i = 0; i < a.size(); i++)
        {

            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && a[dq.back()] > a[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                maxi = max(maxi, a[dq.front()]);
                // cout << " k=" << k << " maxi" << maxi << " a[dq.front()=" << a[dq.front()] << endl;
            }
        }
        // cout << endl;
        ans.push_back(maxi);
    }
    return ans;
}*/