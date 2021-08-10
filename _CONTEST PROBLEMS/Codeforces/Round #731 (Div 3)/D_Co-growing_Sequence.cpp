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
        vector<int>v ={0};
        int ans = arr[0];
        for(int i=1;i<n;i++)
        {
            int temp = arr[i] ^ ans;
            ans = temp & ans;
            v.push_back(ans);
            ans = ans ^ arr[i];
        }
        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}