#include<bits/stdc++.h>
using namespace std;
int Kadane(int n, int a[])
{
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
    return max_sum;
}
int main()
{
    int n=7;
    int a[n]={4,-4,6,-6,10,-11,12};
    int wrap_sum;
    int non_wrapsum=Kadane(n,a);
    int total_sum=0;
    for(int i=0;i<n;i++)
    {
        total_sum +=a[i];
        a[i]=-a[i];
    }
    wrap_sum=total_sum + Kadane(n,a);
    cout<<max(wrap_sum,non_wrapsum);
    return 0;
}