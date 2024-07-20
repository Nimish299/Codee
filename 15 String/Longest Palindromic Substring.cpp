
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string expand_center(int l, int r, string s)
    {

        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;

        int maxLength = 0;
        string longest;
        for (int i = 0; i < s.size() - 1; i++)
        {
            string odd = expand_center(i, i, s);
            string even = expand_center(i, i + 1, s);

            if (odd.size() > maxLength)
            {
                maxLength = odd.size();
                longest = odd;
            }
            if (even.size() > maxLength)
            {
                maxLength = even.size();
                longest = even;
            }
        }
        return longest;
    }
};
int main()
{
    Solution solution;
    string input;

    // cout << "Enter a string to reverse its words: ";
    getline(cin, input);

    string result = solution.longestPalindrome(input);
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