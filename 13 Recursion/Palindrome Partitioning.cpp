
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isPalindrome(const std::string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void fnc(int i, string s, vector<vector<string>> &ans, vector<string> &ds)
    {
        if (i == s.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                ds.push_back(s.substr(i, j - i + 1));
                fnc(j + 1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        fnc(0, s, ans, ds);
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
