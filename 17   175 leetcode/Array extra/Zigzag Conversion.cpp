
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        if (numRows == 1)
            return s; // No zigzag pattern if only one row

        vector<string> ans(numRows);
        bool flag = false;
        int i = 0;

        for (auto ch : s)
        {
            ans[i] += ch;

            if (i == 0 || i == numRows - 1)
                flag = !flag;

            if (flag)
                i += 1;
            else
                i -= 1;
        }

        string result;
        for (auto &str : ans)
        {
            result += str;
        }

        return result;
    }
};
int main()
{

    cout << "cc" << endl;
}
