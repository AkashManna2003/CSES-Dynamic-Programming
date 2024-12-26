#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int dp[1000100][2];

void solve()
{
    for(int i = 1;i<=1000000;i++)
    {
        if(i==1)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        else
        {
            dp[i][0] = (2*dp[i-1][0] + dp[i-1][1])%mod;
            dp[i][1] = (dp[i-1][0] + 4*dp[i-1][1])%mod;
        }
    }
    //cout << dp[i][0] + dp[i][1] << "\n";
}

signed main()
{
    int t;
    cin >> t;
    solve();
    while(t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1])%mod << "\n";
    }
    return 0;
}