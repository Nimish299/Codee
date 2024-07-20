#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int maxarea = 0;
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int distance = right - left;
            int area = 0;
            if (height[left] >= height[right])
            {

                area = distance * height[right];
                right--;
            }
            else
            {

                area = distance * height[left];
                left++;
            }

            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};