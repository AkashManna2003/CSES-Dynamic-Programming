#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

string a, b;
int n, m;
int dp[5001][5001];

void solve()
{
    cin >> a >> b;
    n = a.length();
    m = b.length();
    for(int i = n;i>=0;i--)
    {
        for(int j = m;j>=0;j--)
        {
            if(i == n || j == m)
            {
                dp[i][j] = (n-i) + (m-j);
            }
            else
            {
                dp[i][j] = min({dp[i][j+1]+1, dp[i+1][j]+1, dp[i+1][j+1]+((a[i]==b[j])?0:1)});
            }
        }
    }
    cout << dp[0][0] << "\n";
}

signed main()
{
    int t;
    solve();
    return 0;
}