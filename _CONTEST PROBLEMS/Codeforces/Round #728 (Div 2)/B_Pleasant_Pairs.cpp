#include<bits/stdc++.h>
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        map<int,int>m;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            
            int x = arr[i];
            for(auto j:m)
            {
                if(j.first>ceil(2*(float)n/x))
                    break;
                if(j.first*x == j.second+i+1)
                {
                    count++;
                }
            }
            m[arr[i]] = i+1;
        }
        cout<<count<<endl;
    }
    return 0;
}
