#include <iostream>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool checkReading(int arr[], int n, int m, int page)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        count = count+arr[i];
        if(count>page)
        {
            count = arr[i];
            m--;
        }
    }

    if(m<=0)
    {
        return false;
    }

    return true; 
}

int minimumPages(int arr[], int n, int m)
{
    //Now since you need to return minimum pages
    //hence your search area is pages
    //At least one student will read the maximum number of pages
    //from the array.
    //In worst case, a student may have to read all the pages.

    //Therefore search area becomes
    //max(Arr)  to total number of pages
    //Now apply binary search and check if each one can read 
    //atleast those many pages

    int s = arr[n-1];
    int e = 0;

    for(int i=0; i<n; i++)
    {
        e = e + arr[i];
    }

    int ans = 0;

    while(s<=e)
    {
        int mid = (s+e)>>1;

        if(checkReading(arr, n, m, mid))
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
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
        int n, m;
        cin>>n>>m;

        int arr[n];

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        int res = minimumPages(arr, n, m);

        cout<<res<<"\n";

        
    }
    return 0;
}