#include <bits/stdc++.h>
#define int long long
using namespace std;

struct project
{
    int start;
    int end;
    int profit;
};

bool comp(project a, project b)
{
    return a.end < b.end;
}

int findbest(vector<int> &endPoints, int val)
{
    auto it = lower_bound(endPoints.begin(),endPoints.end(),val);
    if(it == endPoints.end())
    {
        return 0;
    }
    else
    {
        it--;
        return 1 + distance(endPoints.begin(),it);
    }
}

int solve(vector<project> &v)
{
    int n = v.size();
    int dp[n+1];
    dp[0] = 0;
    vector<int> endPoints;
    for(int i = 1;i<v.size();i++)
    {
        endPoints.push_back(v[i].end);
    }
    for(int i = 1;i<n;i++)
    {
        int op1 = dp[i-1];
        int op2 = v[i].profit;
        int j = findbest(endPoints,v[i].start);
        op2 += dp[j];
        dp[i] = max(op1,op2);
        //cout << dp[i] << endl;
    }
    return dp[n-1];
}

signed main()
{
    int n;
    cin >> n;
    vector<project> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].start >> v[i].end >> v[i].profit;
    }
    sort(v.begin()+1, v.end(), comp);
    cout << solve(v) << "\n";
    return 0;
}                               