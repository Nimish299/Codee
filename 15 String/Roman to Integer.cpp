

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {

        int n = s.size();

        unordered_map<char, int> m;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && m[s[i]] < m[s[i + 1]])
            {

                ans += m[s[i + 1]] - m[s[i]];
                i++;
            }
            else
            {

                ans += m[s[i]];
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string input;

    // cout << "Enter a string to reverse its words: ";
    getline(cin, input);

    string result = solution.romanToInt(input);
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