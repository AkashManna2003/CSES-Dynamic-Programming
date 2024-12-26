#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int tilings[1001][(1<<10)];
int n, m;

void fill_column(int column, int idx, int curr_mask, int next_mask)
{
    if(idx == n)
    {
        tilings[column+1][next_mask] = (tilings[column+1][next_mask] + tilings[column][curr_mask])%mod;
        return;
    }
    if(curr_mask & (1<<idx))
    {
        fill_column(column, idx+1, curr_mask, next_mask);
    }
    else
    {
        fill_column(column, idx+1, curr_mask, next_mask | (1<<idx));
        if(idx+1 < n && (!(curr_mask & (1<<(idx+1)))))
        {
            fill_column(column, idx+2, curr_mask, next_mask);
        }
    }
}

int main()
{
    cin >> n >> m;
    tilings[0][0] = 1;
    for(int column = 0;column<m;column++)
    {
        for(int mask = 0;mask<(1<<n);mask++)
        {
            if(tilings[column][mask] > 0)
            {
                fill_column(column, 0, mask, 0);
            }
        }
    }
    cout << tilings[m][0] << "\n";
    return 0;
}