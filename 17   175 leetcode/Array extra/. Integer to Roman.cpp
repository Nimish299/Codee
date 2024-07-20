
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, std::string>> romanMap = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};

        std::string result = "";

        // Iterate over the mapping
        for (const auto &pair : romanMap)
        {
            // While num is greater than or equal to the current value, append the corresponding Roman numeral
            while (num >= pair.first)
            {
                result += pair.second;
                num -= pair.first;
            }
        }
    }
};
int main()
{

    cout << "cc" << endl;
}
