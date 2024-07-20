

#include <bits/stdc++.h>

using namespace std;

int main()
{

    cout << "cc" << endl;
}

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
            }
            else
            {
                i++; // Only increment i if no element is erased
            }
        }
        return nums.size();
    }
};

/*


 int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];  // Swap with the last element
                n--;  // Reduce the size of the vector
            } else {
                i++;  // Move to the next element
            }
        }

        return n;  // Return the new size of the modified vector
 */