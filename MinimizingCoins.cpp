#include <bits/stdc++.h>
using namespace std;
 
long long n,k;
long long c[101];
long long dp[1001000];
 
long long rec(long long amt)//returns the minimum number of coins
{
	if(amt == 0)
		return 0;
	if(dp[amt]!=-1)
		return dp[amt];
	long long ans = INT_MAX;
	for(int i = 0;i<n;i++)
	{
		long long subpr = (amt-c[i]>=0)?rec(amt - c[i]):INT_MAX;
		if(subpr!=INT_MAX && subpr + 1<ans)
			ans = subpr + 1;
	}
	return dp[amt] = ans;
}
 
int main()
{
	cin >> n >> k;
	for(int i = 0;i<n;i++)
	{
		cin >> c[i];
	}
	memset(dp,-1,sizeof(dp));
	long long a = rec(k);
	if(a!=INT_MAX)
		cout << a << "\n";
	else
		cout << "-1" << "\n";
	return 0;
}