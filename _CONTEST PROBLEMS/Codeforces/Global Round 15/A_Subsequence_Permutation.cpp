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
        string s1 = s;
        sort(s1.begin(),s1.end());
        int count =0;
        
        for(int i=0;i<n;i++)
        {
            if(s1[i] != s[i])
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}