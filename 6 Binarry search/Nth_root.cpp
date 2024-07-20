
#include <bits/stdc++.h>

using namespace std;

int NthRoot(int n, int m)
{
    // Write your code here.
    // Write your code here.
    // Write your code here.
    int l = 1;
    int r = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        //  cout << mid << "    >" << pow(mid, n) << "  >>" << m << endl;
        if (pow(mid, n) == m)
        {
            // cout << "hy";
            return mid;
        }
        if (pow(mid, n) < m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{

    cout << "cc" << endl;
}
