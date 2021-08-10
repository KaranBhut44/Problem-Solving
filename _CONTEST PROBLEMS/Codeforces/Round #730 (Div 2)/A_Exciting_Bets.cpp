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
        ll a,b;
        cin>>a>>b;
        ll diff = max(a,b) - min(a,b);
        if(diff==0)
        {
            cout<<0<<" "<<0<<endl;
            continue;
        }
        ll up = min(a,b)%diff;
        ll down = diff - up;
        cout<<diff<<" "<<min(up,down)<<endl;
    }
    return 0;
}