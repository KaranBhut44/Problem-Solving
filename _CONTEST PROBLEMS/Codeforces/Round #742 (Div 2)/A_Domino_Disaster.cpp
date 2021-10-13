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
        string s;
        cin>>s;
        string s1 ="";
        for(auto i:s)
        {
            if(i == 'L' || i == 'R')
                s1 += i;
            else if(i == 'U')
                s1 += 'D';
            else
                s1 += 'U';
        }
        cout<<s1<<endl;
    }
    
    return 0;
}