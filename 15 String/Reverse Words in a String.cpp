
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int i = 0,
            r = 0, l = 0;
        int n = s.size();
        while (i < n)
        {

            while (i < n && s[i] != ' ')
            {
                s[r] = s[i];
                r++;
                i++;
            }

            if (l < r)
            {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }
        return s.substr(0, r - 1);
    }
};
int main()
{
    Solution solution;
    string input;

    // cout << "Enter a string to reverse its words: ";
    getline(cin, input);

    string result = solution.reverseWords(input);
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
