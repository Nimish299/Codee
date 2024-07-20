
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int leftmax = 0;
        int rightmax = 0;
        int result = 0;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] > leftmax)
                    leftmax = height[l];
                else
                    result += leftmax - height[l];
                l++;
            }
            else
            {
                if (height[r] > rightmax)
                    rightmax = height[r];
                else
                    result += rightmax - height[r];
                r--;
            }
        }
        return result;
    }
};

int main()
{

    cout << "cc" << endl;
    int a, v;
    cin >> a;
    cin >> v;
    int c;
    cin >> c;
    if (c == 1)
        cout << a + v;
    else
        cout << a - v;
}
