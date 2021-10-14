#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vector<int>v = {a,b,c};
        sort(v.begin(),v.end());
        if(a==b && b==c)
        {
            cout<<1<<" "<<1<<" "<<1<<endl;
            continue;
        } 
        if(v[1] == v[2])
        {
            int sum1 = v[1]+1;
            cout<<sum1-a<<" "<<sum1-b<<" "<<sum1-c<<endl;
            continue;
        }
        int sum1 = v[2];
        if(a == sum1)
            cout<<0<<" ";
        else
            cout<<sum1-a+1<<" ";
        if(b == sum1)
            cout<<0<<" ";
        else
            cout<<sum1-b+1<<" ";
        if(c == sum1)
            cout<<0<<endl;
        else
            cout<<sum1-c+1<<endl;

    }
    return 0;
}