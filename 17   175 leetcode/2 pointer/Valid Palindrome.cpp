#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlphanumeric(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    char toLowerCase(char c)
    {
        if (c >= 'A' && c <= 'Z')
        {
            return c + ('a' - 'A');
        }
        return c;
    }
    bool isPalindrome(string s)
    {
        string check = "";
        for (char c : s)
        {
            // if (isalnum(c))
            if (isAlphanumeric(c))
            {
                {
                    check += toLowerCase(c);
                    //  check+= tolower(c);
                }
            }
        }
        int left = 0;
        int right = check.length() - 1;
        int counter = 0;
        while (left < right && check[left] == check[right])
        {

            left++;
            right--;
            counter++;
        }
        if (counter == check.length() / 2)
            return true;
        return false;
    }
};