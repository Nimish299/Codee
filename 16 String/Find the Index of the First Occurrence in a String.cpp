
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        int i = 0,
            j = 0;
        int ans;
        while (i < needle.size())
        {
            if (haystack[i] == needle[j])
            {
                ans = i;
                while (haystack[i] == needle[j])
                {

                    i++;
                    j++;
                    if (j == haystack.size() - 1)
                        return ans;
                }
                i = ans;
            }
            j = 0;
            i++;
        }
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

// size_t found = haystack.find(needle);
// if (found != string::npos)
//     return found;
// return -1;
// return haystack.find(needle);
