
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }

        string s = countAndSay(n - 1);
        int c = 1;
        string ans = "";
        int si = s.size();
        cout << "S=" << s << "si=" << si << endl;

        for (int i = 1; i < si; i++)
        {
            cout << "s[i]=" << s[i] << endl;
            if (s[i] == s[i - 1])
            {
                c++;
            }
            else
            {
                ans += to_string(c) + s[i - 1];
                c = 1;
            }
        }
        ans += to_string(c) + s[si - 1];
        cout << "ans=" << ans << endl;
        return ans;
    }
};

int main()
{
    Solution solution;
    string input;

    // cout << "Enter a string to reverse its words: ";
    // getline(cin, input);
    int c;

    cin >> c;

    string result = solution.countAndSay(c);
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