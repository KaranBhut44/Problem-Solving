#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<int,int> p1,pair<int,int>p2)
{
    return p1.first>p2.first;
}
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
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[i] = {temp,i+1};
    }
    sort(arr,arr+n,comp);
    cout<<arr[1].second;
 
    return 0;
}