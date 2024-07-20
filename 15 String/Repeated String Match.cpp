

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        string s = a;
        int c = 1;
        while (s.size() < b.size())
        {
            s += a;
            c++;
        }
        if (s.find(b) != -1)
            return c;
        c++;
        s += a;
        if (s.find(b) != -1)
            return c;
        return -1;
    }
};
int main()
{
    Solution solution;
    string input;

    // cout << "Enter a string to reverse its words: ";
    getline(cin, input);

    string result = solution.repeatedStringMatch(input, input);
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