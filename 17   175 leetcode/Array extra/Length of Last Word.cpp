
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        bool foundChar = false;

        // Traverse the string from end to start
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                // When we encounter a non-space character, we start counting
                foundChar = true;
                length++;
            }
            else if (foundChar)
            {
                // If we encounter a space after starting to count, we're done
                break;
            }
        }

        return length;
    }
};
int main()
{

    cout << "cc" << endl;
}
