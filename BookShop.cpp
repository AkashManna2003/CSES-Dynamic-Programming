#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n,k;
    cin >> n >> k;
    vector<int> price(n);
    vector<int> page(n);
    for(int i = 0;i<n;i++)
    {
        cin >> price[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin >> page[i];
    }
    int dp[k+1];
    memset(dp,0,sizeof(dp));
    for(int i = 0;i<n;i++)
    {
        for(int j = k;j>=price[i];j--)
        {
            dp[j] = max(dp[j],dp[j-price[i]] + page[i]);
        }
    }
    cout << dp[k] << "\n";
    return 0;
}