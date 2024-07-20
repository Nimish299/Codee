
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), std::greater<int>());
        int ans;
        int n = citations.size();
        for (int i = 0; i < n; i++)
        {
            if (citations[i] >= i + 1)
            {
                ans = i + 1;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
int main()
{

    cout << "cc" << endl;
}
