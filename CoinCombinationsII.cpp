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
    sort(v.begin(),v.end());
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i = 0;i<n;i++)
    {
        for(int j = v[i];j<=x;j++)
        {
            dp[j] = (dp[j] + dp[j-v[i]])%mod;
        }
    }
    std::cout << dp[x] << "\n";
    return 0;
}