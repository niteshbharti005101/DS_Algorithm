#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long int ll;

//in worst case all the cows can be placed in the same stall
//i.e distance = 0
//in best case the cows can be placed at the extreme points
//i.e distance = n-1, where n is the coordinate of the extreme shop

//Therefore search area is monotonic as is 0 to n-1
bool canPlaceCows(ll arr[], ll c, ll dist, ll n)
{
    ll prevCow = arr[0];
    c = c-1;
    for(ll i=1; i<n; i++)
    {
        if((arr[i] - prevCow)>=dist)
        {
            //then cow can be placed
            c--;
            prevCow = arr[i];
        }

        if(c==0)
        {
            break;
        }
    }

    if(c==0)
    {
        return true;
    }

    return false;
}

ll findDistance(ll arr[], ll n, ll c, ll n1)
{
    ll s = 0;
    ll e = n-1;
    ll ans = 0;
    while(s<=e)
    {
        //dividing by 2
        ll mid = (s+e)>>1;
        //cout<<"Mid "<<mid<<"\n";
        if(canPlaceCows(arr, c, mid, n1))
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }

    return ans;
}
int main()
{
    int t;
    fastio
    cin>>t;
    while(t--)
    {
        ll n, c;
        cin>>n>>c;

        ll arr[n];
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        sort(arr, arr+n);

        ll k = arr[n-1];

        ll max_distance = findDistance(arr, k, c, n);

        cout<<max_distance<<"\n";
    }
    return 0;
}
