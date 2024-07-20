#include <bits/stdc++.h>

using namespace std;
//better
int minCoins(int coins[], int m, int V)
{
    // base case
    if (V == 0)
        return 0;

    // Initialize result
    int res = INT_MAX;

    // Try every coin that has smaller value than V
    for (int i = 0; i < m; i++)
    {
        if (coins[i] <= V)
        {
            int sub_res = minCoins(coins, m, V - coins[i]);

            // Check for INT_MAX to avoid overflow and see if
            // result can minimized
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}
int main()
{
    int V = 49;
    vector<int> ans;
    int n;
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end()); // Sort the vector
    // int n = 9;
    for (int i = n - 1; i >= 0; i--)
    {
        while (V >= coins[i])
        {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}