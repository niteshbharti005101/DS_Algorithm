#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=7;
    int a[n]={10,7,4,6,8,10,11};
    int ans=2,curr=2,j=2;
    int pd=a[1]-a[0];
    while(j<n)
    {
        if(pd==a[j]-a[j-1])
        {
            curr++;
        }
        else
        {
            pd=a[j]-a[j-1];
            curr=2;
        }
        ans=max(curr,ans);
        j++;
    }
    cout<<ans;
    return 0;
}