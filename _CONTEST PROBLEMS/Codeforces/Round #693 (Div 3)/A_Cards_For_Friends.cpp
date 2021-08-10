#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int w,h,n;
        cin>>w>>h>>n;
        long long p =w*h;
        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }    
        else if(p%2!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int count=0;
        while(p%2==0)
        {
            count+=1;
            p/=2;
        }
        if(pow(2,count)>=n)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}