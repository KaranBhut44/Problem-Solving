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
        string s = to_string(n);
        string s1="",s2="";
        int m = s.size();
        for(int i=0;i<m;i++)
        {
            if(i%2==0)
                s1+=s[i];
            else
                s2+=s[i];
        }
        cout<<(ll)(stoi(s1)+1)*(s2==""?1:(1+stoi(s2)))-2<<endl;
    }
    return 0;
}