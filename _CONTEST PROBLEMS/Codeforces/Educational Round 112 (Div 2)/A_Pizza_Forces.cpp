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
        ll n;
        cin>>n;
        ll count =0;
        if(n>10)
        {
            ll m = n/6;
            if(m == 1)
            {
                n -= m*6;
                count += m*15;
            }
            else
            {
                n -= (m-1)*6;
                count += (m-1)*15;
            }
        }
        while(n>0)
        {if(n<=6 || n>10)
        {
            count+=15;
            n-=6;
        }
        else if(n<=8)
        {
            count+=20;
            n-=8;
        }
        else if(n<=10)
        {
            count+=25;
            n-=10;
        }
        }
        cout<<count<<endl;
    }
    return 0;
}