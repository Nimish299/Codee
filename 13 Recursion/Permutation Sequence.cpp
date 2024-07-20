
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> v;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans = "";
        k--;
        while (true)
        {
            ans += to_string(v[k / fact]);
            v.erase(v.begin() + k / fact);
            if (v.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / v.size();
        }
        return ans;
    }
};
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
