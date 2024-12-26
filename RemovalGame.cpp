#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int dp[n+1][n+1];
    for(int i = n-1;i>=0;i--)
    {
        for(int j = i;j<n;j++)
        {
            if(i == j)
            {
                dp[i][j] = arr[i];
            }
            else
            {
                dp[i][j] = max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
            }
        }
    }
    cout << (sum + dp[0][n-1])/2 << "\n";
}

signed main()
{
    solve();
    return 0;
}