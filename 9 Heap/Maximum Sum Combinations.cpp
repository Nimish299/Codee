
#include <bits/stdc++.h>

using namespace std;
vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    int n1 = A.size();
    int n2 = B.size();
    priority_queue<pair<int, pair<int, int>>> pq;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    set<pair<int, int>> s;
    pq.push({A.back() + B.back(), {n1 - 1, n2 - 1}});
    s.insert({n1 - 1, n2 - 1});

    vector<int> ans;
    while (C-- && !pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int sum = p.first;
        ans.push_back(sum);

        int i = p.second.first;
        int j = p.second.second;

        if (i > 0 && s.find({i - 1, j}) == s.end())
        {
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            s.insert({i - 1, j});
        }
        if (j > 0 && s.find({i, j - 1}) == s.end())
        {
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            s.insert({i, j - 1});
        }
    }
    return ans;
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
