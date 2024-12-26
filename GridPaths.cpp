#include<bits/stdc++.h>
#define int long long
const long long mod = 1e9+7;
using namespace std;

bool isValid(int i,int j,int n)
{
    if(i>=0 && i<n && j>=0 && j<n)
        return true;
    return false;
}

signed main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
    }
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = (v[0][0]=='.')?1:0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i==0 && j==0)
                continue;
            if(v[i][j]=='.')
            {
                if(isValid(i,j-1,n) && v[i][j-1]=='.' )
                    dp[i][j] = (dp[i][j-1] + dp[i][j])%mod;
                if(isValid(i-1,j,n) && v[i-1][j]=='.' )
                    dp[i][j] = (dp[i-1][j] + dp[i][j])%mod;
            }
        }
    }
    cout << dp[n-1][n-1] << "\n";
    return 0;
}
