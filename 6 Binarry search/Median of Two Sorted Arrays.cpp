#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        
        // Indices to find the middle elements
        int medianIdx1 = (total - 1) / 2;
        int medianIdx2 = total / 2;
        
        int i = 0, j = 0, count = 0;
        int num1 = 0, num2 = 0;
        
        while (count <= medianIdx2) {
            int val;
            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }
            
            if (count == medianIdx1) {
                num1 = val;
            }
            if (count == medianIdx2) {
                num2 = val;
            }
            count++;
        }
        
        // If the total number of elements is odd, return the middle element.
        // If even, return the average of the two middle elements.
        if (total % 2 == 0) {
            return (num1 + num2) / 2.0;
        } else {
            return num2;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;  // Output: 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;  // Output: 2.5

    return 0;
}
