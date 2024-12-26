#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long mod = 1e9+7;

signed main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = n;i>=0;i--)
    {
        for(int last = 1;last<=m;last++)
        {
            if(i==n)
                dp[i][last] = 1;
            else{
                if(v[i] == 0)
                {
                    for(int diff = -1;diff<=1;diff++)
                    {
                        int curr = last + diff;
                        if(curr<=m && curr>=1){
                            dp[i][last] += dp[i+1][curr];
                            dp[i][last] %= mod;
                        }
                    }
                }
                else{
                    int curr = v[i];
                    if(abs(curr-last)<=1)
                        dp[i][last] = dp[i+1][curr];
                }
            }
        }
    }
    int ans = 0;
    if(v[0] == 0)
    {
        for(int cur = 1;cur<=m;cur++)
        {
            ans += dp[1][cur];
            ans %= mod;
        }
    }
    else
    {
        int cur = v[0];
        ans += dp[1][cur];
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}