#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll check(vector<int> &A, vector<int> &B, int C,int n,int index,ll **dp)
{
    if(n==0 || C<=0)
        return 0;
    if(dp[C][n]>-1)
        return dp[C][n];
    ll max1 = check(A,B,C,n-1,index+1,dp); 
    if(B[index] <= C)
    {
        max1 = max(max1, A[index] + check(A,B,C-B[index],n-1,index+1,dp));
    }
    dp[C][n] = max1;
    return max1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,C;
    cin>>n>>C;
    vector<int>A,B;
    for(int i=0;i<n;i++)
    {
        int val,wet;
        cin>>wet>>val;
        A.push_back(val);
        B.push_back(wet);
    }
    ll **dp = new ll*[C+1];
    for(int i=0;i<=C;i++)
    {
        dp[i] = new ll[n+1];
        for(int j=0;j<=n;j++)
            dp[i][j] = -1;
    }
    cout<<check(A,B,C,n,0,dp);
    return 0;
}
