#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, limit;
    cin >> n >> limit;
    int a[n];
    for(int i = 0;i<n;i++) 
        cin >> a[i];
    
    vector<pair<int, int> > dp(1<<n, {1e9, 1e9});
    dp[0] = {1, 0};
    for(int mask = 1;mask < (1<<n);mask++)
    {
        for(int bit = 0;bit<n;bit++)
        {
            if((mask & (1<<bit)))
            {
                int space_taken = dp[mask^(1<<bit)].second;
                if(space_taken + a[bit] <= limit)
                {
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first, space_taken + a[bit]});
                }
                else
                {
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first + 1, a[bit]});
                }
            }
        }
    }
    cout << dp[(1<<n)-1].first << "\n";
}