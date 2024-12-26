#include <bits/stdc++.h>
using namespace std;
long long n;
long long mod = 1e9 + 7;
long long dp[1000001];
 
long long rec(long long n)
{
	//cout<<n<<endl;
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	long long ans = 0;
	for(int i = 1;i<=6;i++)
	{
		long long subprob = ((n-i)>=0)?rec(n - i):0;
		subprob = subprob%mod;
		ans = (ans + subprob)%mod;
	}	
	return dp[n] = ans;
}
 
int main()
{
	cin >> n;
	memset(dp,-1,sizeof(dp));
	cout << rec(n) << "\n";
	return 0;
}
