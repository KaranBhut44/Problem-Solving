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
    int n;
    cin>>n;
    if(n<=125 && n>=1)
        cout<<4;
    else if(n<=211)
        cout<<6;
    else
        cout<<8;
    return 0;
}
