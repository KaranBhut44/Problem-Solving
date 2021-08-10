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
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    unordered_map<string,int>m;
    m["H"] = 0;
    m["2B"] = 0;
    m["3B"] = 0;
    m["HR"] = 0;
    m[a]++;
    m[b]++;
    m[c]++;
    m[d]++;
    if(m["H"] && m["2B"] && m["3B"] && m["HR"])
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}