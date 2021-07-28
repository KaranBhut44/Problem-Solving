#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fun(int *arr,int n,int index,int *dp)
{
    int min1=INT_MAX;
    if(index>=n-1)
        return 0;
    if(dp[index]>-1)
        return dp[index];
    if(index+2<n)
        min1 = min(min1, abs(arr[index]-arr[index+2]) + fun(arr,n,index+2,dp));
    if(index+1<n)
        min1 = min(min1, abs(arr[index]-arr[index+1]) + fun(arr,n,index+1,dp));
    dp[index] = min1;
    return min1;
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
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *dp = new int[n];
    for(int i=0;i<n;i++)
        dp[i] = -1;
    cout<<fun(arr,n,0,dp);
    return 0;
}