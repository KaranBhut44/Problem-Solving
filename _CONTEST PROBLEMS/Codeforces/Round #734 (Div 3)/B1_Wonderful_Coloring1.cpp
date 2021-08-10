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
        unordered_map<char,int>m;
        for(auto i:s)
            m[i]++;
        int n = m.size();
        int r =0,g=0;
        int count = 0;
        for(auto i:m)
        {   
            if(i.second>=2)
            {
                r++;
                g++;
            }
            else if(i.second == 1)
            {
                if(count%2 == 0)
                    r++;
                else
                    g++;
                count++;
            }
        }
        cout<<min(r,g)<<endl;
    }
    return 0;
}