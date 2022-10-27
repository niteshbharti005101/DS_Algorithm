#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long int ll;
ll solve(ll n, vector<ll> &dp)
{
    if(n==1)
    {
        return 0;
    }

    if(dp[n]!=0)
    {
        return dp[n];
    }

    ll ops1, ops2, ops3;
    ops1 = ops2 = ops3 = LONG_MAX;
    if(n%2==0)
    {
        ops1 = solve(n/2, dp) + 1;
    }
    else if(n%3==0)
    {
        ops2 = solve(n/3, dp) + 1;
    }
    ops3 = solve(n-1, dp) + 1;

    ll ans = min(ops1, min(ops2, ops3));
    

    return dp[n] = ans;
}

int main()
{
    int t;
    fastio
    cin>>t;
    int i = 0;
    vector<ll> dp(100000000, 0);
    dp[1] = 0;
    while(t--)
    {
        
        ll n;
        cin>>n;
        ll val = solve(n, dp);
        cout<<"Case "<<++i<<": "<<val<<"\n";
    }
    return 0;
}