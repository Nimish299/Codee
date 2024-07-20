//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // int k = A.size();
        int maxl = 0;
        unordered_map<long long, int> PrefixSum;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            // cout << "A[" << i << "]=" << A[i] << endl;
            // cout << "sum=" << sum << endl;
            if (sum == 0) // comes k
            {
                maxl = max(maxl, i + 1);
            }
            long long rem = sum - 0; // comes k
            if (PrefixSum.find(rem) != PrefixSum.end())
            {

                maxl = max(maxl, i - PrefixSum[rem]);
            }
            if (PrefixSum.find(sum) == PrefixSum.end())
                PrefixSum[sum] = i;
        }

        return maxl;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

/*

int maxLen(vector<int> &A, int n)
    {

        int l = 0;
        int r = 0;
        int sum = 0;
        // int i = 0;
        int c = 0;
        // cout << c;
        while (r < A.size())
        {
            sum += A[r];

            // cout << "l=" << l << "  r =" << r << endl;
            // cout << "sum=" << sum << r - l + 1 << endl;
            if (sum == 0)
            {
                c = max(c, r - l + 1);
            }
            if (r == A.size() - 1 && l < A.size())
            {
                l++;
                r = l;
                sum = 0; // Reset sum when starting a new subarray
            }
            else
                r++;
        }
        return c;
    }
*/