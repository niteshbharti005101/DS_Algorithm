#include<bits/stdc++.h>
using namespace std;
int H_D(string s)
{
    int l=s.size();
    int ans=0,p=0;
    for(int i=l-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            ans =ans + ( (s[i]-48)*pow(16,p) );
        }
        if(s[i]>='A' && s[i]<='F')
        {
            ans = ans + ( (s[i]-55)*pow(16,p) );
        }
        p++;
    }
    return ans;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<H_D(s);
    return 0;
}