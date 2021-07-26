#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll prefix_sum[n];
    prefix_sum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i]; 
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<prefix_sum[r-1] - (l>1?prefix_sum[l-1-1]:0)<<endl;
    }
    return 0;
}