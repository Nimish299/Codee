//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{

public:
    bool static comparison(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // Sort jobs according to their profit
        sort(arr, arr + n, comparison);

        int maxd = 0;
        for (int i = 0; i < n; i++)
        {
            maxd = max(maxd, arr[i].dead);
        }

        // Create a slot array to keep track of free time slots
        vector<int> slot(maxd, -1);

        int c = 0; // Count of jobs done
        int p = 0; // Total profit

        for (int i = 0; i < n; i++)
        {
            // Find a free slot for this job (Note that we start from the last possible slot)
            for (int j = arr[i].dead - 1; j >= 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = arr[i].id; // Assign this job to the free slot
                    c++;
                    p += arr[i].profit;
                    break;
                }
            }
        }
        return {c, p}; // Return the results
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends