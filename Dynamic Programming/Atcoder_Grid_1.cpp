#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    char arr[h][w];
    int **dp = new int*[h];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<h;i++)
    {
        dp[i] = new int[w];
        for(int j=0;j<w;j++)
        {
            dp[i][j] = 0;
        }
    }
    int i = w-1;
    while(i>=0 && arr[h-1][i] == '.')
    {
        dp[h-1][i] = 1;
        i--;
    }
    i = h-1;
    while(i>=0 && arr[i][w-1] == '.')
    {
        dp[i][w-1] = 1;
        i--;
    }
    for(int i=h-2;i>=0;i--)
    {
        for(int j=w-2;j>=0;j--)
        {
            if(arr[i][j] == '.')
                dp[i][j] = ((ll)dp[i+1][j] + dp[i][j+1])%mod;
        }
    }
    cout<<dp[0][0];
    return 0;
}