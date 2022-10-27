#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=8;
    int a[8]={1,2,0,7,2,0,2,2};
    int count=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[i+1] && a[i]>mx)
        {
            count++;
            mx=max(mx,a[i]);
        }
    }
    cout<<count;
    return 0;
}