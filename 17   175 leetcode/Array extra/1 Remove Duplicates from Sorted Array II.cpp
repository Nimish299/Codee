
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    { // run two pointer i,s and i goes frw s is position where you willl add new item it check condition not more that 2
        int n = nums.size();
        if (n <= 2)
            return n; // No duplicates if size <= 2

        int s = 2; // Start placing elements from index 2 (since first two can always stay)

        for (int i = 2; i < n; i++)
        {
            if (nums[i] != nums[s - 2])
            {
                nums[s] = nums[i];
                s++;
            }
        }

        return s;
    }
};
int main()
{

    cout << "cc" << endl;
}
