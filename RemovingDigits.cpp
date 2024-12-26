#include<bits/stdc++.h>
#define int long long
using namespace std;

set<int> getDigits(int n)
{
    set<int> s;
    while(n)
    {
        s.insert(n%10);
        n /= 10;
    }
    return s;
}

signed main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1);
    for(int i = 0;i<=n;i++)
    {
        if(i==0)
            dp[i] = 0;
        else
        {
            set<int> s = getDigits(i);
            dp[i] = 1e18;
            for(auto d:s)
            {
                dp[i] = min(dp[i],dp[i-d]+1);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}