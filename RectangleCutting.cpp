#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int a, b;
int dp[501][501];

void solve()
{
    cin >> a >> b;
    for(int x = 1;x<=500;x++)
    {
        for(int y = 1;y<=500;y++)
        {
            if(x==y)
            {
                dp[x][y] = 0;
            }
            else
            {
                dp[x][y] = 1e9;
                for(int a = 1;a<=x-1;a++)
                {
                    dp[x][y] = min(dp[x][y], 1 + dp[a][y] + dp[x-a][y]);
                }
                for(int b = 1;b<=y-1;b++)
                {
                    dp[x][y] = min(dp[x][y], 1 + dp[x][b] + dp[x][y-b]);
                }
            }
        }
    }
    cout << dp[a][b] << "\n";
}

signed main()
{
    solve();
    return 0;
}