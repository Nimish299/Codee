
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        unordered_set<int> st;
        int l = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        for (auto it : st)
        {

            if (st.find(it - 1) == st.end())
            {
                int c = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    c = c + 1;
                    x = x + 1;
                }
                l = max(l, c);
            }
        }
        return l;
    }
};
int main()
{
    Solution solution;

    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "The input array is: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    int result = solution.longestConsecutive(nums);
    cout << "The length of the longest consecutive sequence is: " << result << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int longestSuccessiveElements(vector<int> &a)
// {

//     // Find the longest sequence:
//     for (auto it : st)
//     {
//         // if 'it' is a starting number:
//         if (st.find(it - 1) == st.end())
//         {
//             // find consecutive numbers:
//             int cnt = 1;
//             int x = it;
//             while (st.find(x + 1) != st.end())
//             {
//                 x = x + 1;
//                 cnt = cnt + 1;
//             }
//             longest = max(longest, cnt);
//         }
//     }
//     return longest;
// }
