
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int j = 0;
        int maxj = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxj >= nums.size())
                return true;
            if (i > maxj)
                return false;

            maxj = max(maxj, nums[i] + i);
        }

        return true;
    }
};

int main()
{

    cout << "cc" << endl;
}
