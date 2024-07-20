
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int i;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (i; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
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
