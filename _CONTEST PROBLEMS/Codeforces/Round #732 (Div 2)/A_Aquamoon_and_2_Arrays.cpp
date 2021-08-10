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
        int a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        int count = 0;
        int i=0,j=0;
        vector<pair<int,int>> v;
        while(i<n && j<n)
        {
            while(i<n && a[i] <= b[i])
            {
                i++;
            }
            while(j<n && a[j] >= b[j])
            {
                j++;
            }
            if(i<n && j<n && abs(a[i] - b[i]) <= abs(a[j] - b[j]))
            {
                int c = abs(a[i] - b[i]);
                while(c--)
                {
                    a[i]--;
                    a[j]++;
                    v.push_back({i+1,j+1});
                }
            }
            else if(i<n && j<n)
            {
                int c = abs(a[j] - b[j]);
                while(c--)
                {
                    a[i]--;
                    a[j]++;
                    v.push_back({i+1,j+1});
                }
            }
            while(i<n && a[i] == b[i])
                i++;
            while(j<n && a[j] == b[j])
                j++;
        }
        if(i<n || j<n)
        {
            cout<<-1<<endl;
        }
        else{
            cout<<v.size()<<endl;
            for(auto i:v)
                cout<<i.first<<" "<<i.second<<endl;
        }
    }
    return 0;
}