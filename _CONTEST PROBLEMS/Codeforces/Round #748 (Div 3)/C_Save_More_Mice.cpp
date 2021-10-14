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
        int n,m;
        cin>>n>>m;
        vector<int>v;
        for(int i=0;i<m;i++)
        {
            int temp;
            cin>>temp;
            v.push_back(n-temp);
        }
        sort(v.begin(),v.end());
        ll sum1 = 0;
        bool flag = true;
        for(int i=0;i<m;i++)
        {
            sum1 += v[i];
            if(sum1 >= n)
            {
                cout<<i<<endl;
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<m<<endl; 
    }
    return 0;
}