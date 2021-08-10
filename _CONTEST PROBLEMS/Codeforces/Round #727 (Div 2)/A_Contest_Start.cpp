#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll approach2(ll n,ll x,ll t)
{
    ll p = t/x + 1;
    ll sum1 = 0;
    if(p < n)
    {
        sum1 = (p - 1)*p / 2;
        sum1 += (n-p)*(p-1);
    }
    else
        sum1 = (n - 1) * n / 2;
    return sum1;
}
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
        ll n,x,t;
        cin>>n>>x>>t;
        cout<<approach2(n,x,t)<<endl;
    }
}