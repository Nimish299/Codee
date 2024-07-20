
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> splitVersion(const string &version)
    {
        vector<int> result;
        stringstream ss(version);
        string item;
        while (getline(ss, item, '.'))
        {
            result.push_back(stoi(item));
        }
        return result;
    }

    int compareVersion(string version1, string version2)
    {
        vector<int> v1 = splitVersion(version1);
        vector<int> v2 = splitVersion(version2);

        int length = max(v1.size(), v2.size());
        for (int i = 0; i < length; ++i)
        {
            int num1 = i < v1.size() ? v1[i] : 0;
            int num2 = i < v2.size() ? v2[i] : 0;

            if (num1 < num2)
                return -1;
            if (num1 > num2)
                return 1;
        }
        return 0;
    }
};
int main()
{
    // Solution solution;
    string input;

    // cout << "Enter a string to reverse its words: ";
    getline(cin, input);

    string result = input;
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