#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int n;

void solve()
{
    cin >> n;
    bitset<100001> temp;
    temp[0] = 1;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin >> x;
        temp |= temp << x;
    }
    vector<int> ans;
    for(int i = 1;i<=100000;i++) //Here the starting value is 1 because we dont want to consider the sum 0 which can be made by taking no coins
    {
        if(temp[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for(auto v:ans)
    {
        cout << v << "\n";
    }
}

signed main()
{
    int t;
    t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}