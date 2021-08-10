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

    int n;
    ll k,x;
    cin>>n>>k>>x;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);

    vector<ll>v;
    for(int i=1;i<n;i++)
    {
        if(arr[i] - arr[i-1] > x)
        {
            ll diff = arr[i] - arr[i-1];
            diff--;
            ll result = diff/x;
            v.push_back(result);
        }
    }
    sort(v.begin(),v.end());
    ll count = 0;
    ll sum1 = 0;
    for(auto i:v)
    {
        if(sum1 + i > k)
            break;
        count++;
        sum1+= i;
    }
    cout<<v.size()+1-count<<endl;
}