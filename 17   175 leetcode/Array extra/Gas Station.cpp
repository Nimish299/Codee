
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    /*greedy as we can say if sum is greater than theier is way and we check from
    starting if negative that is not possible
    but if possible than we have to take care and check if it becom b=negative
     than we can not take til that as ther is some negative
    valey which dectrease it to 0 */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        // vector<int> cur;
        int scur = 0;
        for (int i = 0; i < n; i++)
        {
            scur += gas[i] - cost[i];
        }
        if (scur < 0)
            return -1;
        int start = 0,
            c = 0;
        for (int i = 0; i < n; i++)
        {

            c += gas[i] - cost[i];
            if (c < 0)
            {
                c = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
int main()
{

    cout << "cc" << endl;
}
