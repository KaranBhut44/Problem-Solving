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
        sort(arr,arr+n);
        int ele = arr[0];
        for(int i=0;i<n;i++)
            arr[i] -= ele;

        unordered_set<int>s;
        for(int i=0;i<n;i++)
            s.insert(arr[i]);
        int ans = *s.begin();
        for(auto i:s)
            ans = __gcd(ans,i);
        if(ans == 0)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}