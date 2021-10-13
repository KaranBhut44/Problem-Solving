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
            
        int a = 0,b=0, c=0;
        for(auto i:s)
        {
            if(i == 'A')
                a++;
            else if(i == 'B')
                b++;
            else
                c++;
        }
        if(a+c == b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}