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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        unordered_map<int,pair<int,int>>m,m1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                m[arr[i]].first += 1;
            }
            else
            {
                m[arr[i]].second += 1;
            }
        }
        sort(arr,arr+n);
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                m1[arr[i]].first += 1;
            }
            else
            {
                m1[arr[i]].second += 1;
            }
        }
        for(auto i:m)
        {
            if(i.second != m1[i.first])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl; 
    }
    return 0;
}
