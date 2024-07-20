
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void subarray(int i, int sum, vector<int> arr, int n, vector<int> &subsetsum)
    {
        if (i == n)
        {
            subsetsum.push_back(sum);
            return;
        }
        subarray(i + 1, sum + arr[i], arr, n, subsetsum);
        subarray(i + 1, sum, arr, n, subsetsum);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> subsetsum;
        subarray(0, 0, arr, n, subsetsum);
        return subsetsum;
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
