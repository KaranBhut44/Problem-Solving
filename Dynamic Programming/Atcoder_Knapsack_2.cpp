#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
int w[100];
int v[100];
ll dp[100][1000001];
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
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<=100000;j++)
        {
            dp[i][j] = inf;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    dp[0][0] = 0;
    dp[0][v[0]] = w[0];
    
    for(int id=1;id<n;id++)
    {
        dp[id][0] = 0;
        for(int j=1;j<=100000;j++)
        {
            dp[id][j] = dp[id-1][j];

            if(j >= v[id])
                dp[id][j] = min(dp[id][j], w[id]+dp[id-1][j-v[id]]);
        }
    }
    ll answer;
    for(int val = 100000;val>=0;val--)
    {
        if(dp[n-1][val] <= C)
        {
            answer = val;
            break;
        }
    }
    cout<<answer;
    return 0;
}
