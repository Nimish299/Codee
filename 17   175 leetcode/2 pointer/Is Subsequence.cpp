#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int lenS = s.length();
        int lenT = t.length();
        int i = 0;
        int j = 0;
        while (i < lenT && j < lenS)
        {
            if (t[i] == s[j])
            {
                j++;
            }
            i++;
        }
        return j == lenS;
    }
};