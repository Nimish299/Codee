
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();

        int i = 0;
        while (i < first.size() && i < last.size() && first[i] == last[i])
        {
            i++;
        }

        return first.substr(0, i);
    }
};
int main()
{
    Solution solution;
    string input;

    // cout << "Enter a string to reverse its words: ";
    getline(cin, input);

    string result = solution.longestCommonPrefix(input);
    cout << result << endl;

    // int a, v, c;
    // cout << "Enter two integers (a and v): ";
    // cin >> a >> v;
    // cout << "Enter 1 for addition or 0 for subtraction: ";
    // cin >> c;

    // if (c == 1)
    //     cout << "Result: " << a + v << endl;
    // else
    //     cout << "Result: " << a - v << endl;

    return 0;
}