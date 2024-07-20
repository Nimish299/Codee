
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        nums.clear();
        for (const int &elem : st)
        {
            nums.push_back(elem);
        }
        return st.size();
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

//  for (int j = 1; j < n; j++) {
//     if (arr[i] != arr[j]) {
//       i++;
//       arr[i] = arr[j];
//     }
//   }