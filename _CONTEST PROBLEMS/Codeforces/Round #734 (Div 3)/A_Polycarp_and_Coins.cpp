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
        int n;
        cin>>n;
        int p = n/3;
        int diff = n - 3*p;
        int s = p;
        int d = p;
        if(diff == 2)
            d++;
        else if(diff == 1)
            s++;
        cout<<s<<" "<<d<<endl;
    }
    return 0;
}