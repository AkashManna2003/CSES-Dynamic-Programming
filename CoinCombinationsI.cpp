#include<bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
using namespace std;

signed main()
{
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
    }
    int dp[x+1];
    for(int i = 0;i<=x;i++)
    {
        if(i==0)
            dp[i] = 1;
        else
        {
            dp[i] = 0;
            for(int j = 0;j<n;j++)
            {
                if((i-v[j])>=0)
                {
                    dp[i] = (dp[i] + dp[i-v[j]])%mod;
                }
            }
        }
    }
    cout << dp[x] << "\n";
    return 0;
}