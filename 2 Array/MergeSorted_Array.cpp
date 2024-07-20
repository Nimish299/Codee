#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

// class Solution
// {
// public:
//     void mergesort(vector<int> &nums1, int m, vector<int> &nums2, int n, int b1, int b2)
//     {
//         if (b1 == m)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 nums1[b1 + i] = nums2[i];
//             }

//             return;
//         }
//         if (nums1[b1] > nums2[b2])
//         {
//             cout << "num1 =" << nums1[b1] << "num2 =" << nums2[b2] << endl;
//             swap(nums1[b1], nums2[b2]);
//             sort(nums2.begin(), nums2.end());
//         }
//         b1++;
//         mergesort(nums1, m, nums2, n, b1, b2);
//     }

//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         mergesort(nums1, m, nums2, n, 0, 0);
//     }
// };

#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int l = m - 1;
        int s = 0;

        while (l >= 0 || s < n)
        {
            if (nums1[l] > nums2[s])
            {
                swap(nums1[l], nums2[s]);
                l--;
                s++;
            }
            else
            {
                break;
            }
        }

        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - m];
        }
        //  sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }
};
int main()
{
    vector<int> nums1 = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0}; // First 5 elements are the actual elements, last 5 are placeholders
    vector<int> nums2 = {2, 4, 6, 8, 10};               // Second array
    int m = 5;                                          // Number of actual elements in nums1
    int n = 5;                                          // Number of elements in nums2

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
