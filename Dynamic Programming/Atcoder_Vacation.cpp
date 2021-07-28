#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fun(vector<vector<int>> &arr,int n,char flag,int index,int **dp)
{
    int max1 = INT_MIN;
    if(index>=n)
        return 0;
    
    if(flag != 'a')
    {
        if(dp[index][0] == -1)
            dp[index][0] = arr[index][0] + fun(arr,n,'a',index+1,dp);
        max1 = max(max1, dp[index][0]);
    }
    if(flag != 'b')
    {
        if(dp[index][1] == -1)
            dp[index][1] = arr[index][1] + fun(arr,n,'b',index+1,dp);
        max1 = max(max1, dp[index][1]);
    }
    if(flag != 'c')
    {
        if(dp[index][2] == -1)
            dp[index][2] = arr[index][2] + fun(arr,n,'c',index+1,dp);
        max1 = max(max1, dp[index][2]);
    }
    return max1;
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
    vector<vector<int>> arr;
    int temp =0;
    for(int i=0;i<n;i++)
    {
        vector<int>v1;
        for(int j=0;j<3;j++)
        {
            int ip;
            cin>>ip;
            v1.push_back(ip);
        }
        arr.push_back(v1);
    }
    int **dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[3];
        for(int j=0;j<3;j++)
            dp[i][j] = -1;
    }
 
    cout<<fun(arr,n,'$',0,dp);
    return 0;
}