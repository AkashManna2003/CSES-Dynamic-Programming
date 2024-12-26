#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    if(sum % 2)
    {
        cout << 0 << "\n";
        return;
    }
    sum/=2;
    int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j <= sum; j++) 
        {
            dp[i][j] = dp[i-1][j];
            int left = j-i;
            if (left >= 0) 
            {
	            (dp[i][j] += dp[i-1][left]) %= mod;
            }
        }
    }
    cout << dp[n-1][sum]%mod << "\n";
}

signed main()
{
    solve();
    return 0;
}