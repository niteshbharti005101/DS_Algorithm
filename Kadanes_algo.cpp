#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=4;
    int a[n]={-1,4,7,2};
    int curr_sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_sum+=a[i];
        if(curr_sum<0)
        {
            curr_sum=0;
        }
        max_sum=max(max_sum,curr_sum);
    }
    cout<<max_sum;
    return 0;
}