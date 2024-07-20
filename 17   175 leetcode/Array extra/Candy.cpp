
#include <bits/stdc++.h>
using namespace std;

// left tyrasfter see back i,i-1
//----->>>>
// right transfer see back i,i+1
//<<----
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candy(n, 1);
        if (n == 1)
            return 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
            {
                candy[i] = candy[i + 1] + 1;
            }
        }
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            t += candy[i];
        }
        return t;
    }
};
int main()
{

    cout << "cc" << endl;
}
