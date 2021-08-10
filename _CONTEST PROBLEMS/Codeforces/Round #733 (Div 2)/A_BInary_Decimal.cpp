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
        string s;
        cin>>s;
        char p = '0';
        for(auto i:s)
        {
            if(i > p)
                p = i;
        }
        int item = p - '0';
        if(item == 0)
            cout<<1<<endl;
        else
            cout<<item<<endl;
    }
    return 0;
}