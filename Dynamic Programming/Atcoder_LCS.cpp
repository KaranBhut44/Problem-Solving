#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[3000][3000];
int choice[3000][3000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    dp[0][0] = 0;
    if(s[0] == t[0])
    {
        dp[0][0] = 1;
        choice[0][0] = 2;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>0)
            {
                dp[i][j] = dp[i-1][j];
                choice[i][j] = 0;
            }
            if(j>0)
            {
                if(dp[i][j-1] > dp[i][j])
                {
                    dp[i][j] = dp[i][j-1];
                    choice[i][j] = 1;
                }
            }
            if(s[i] == t[j])
            {
                int ans = 1;
                if(i>0 && j>0)
                {
                    ans = 1 + dp[i-1][j-1];
                }
                if(ans > dp[i][j])
                {
                    dp[i][j] = ans;
                    choice[i][j] = 2;
                }
            }
        }
    }
    int i = n-1,j = m-1;
    string ans;

    while(i>=0 && j>=0)
    {
        if(choice[i][j] == 0)
            i--;
        else if(choice[i][j] == 1)
            j--;
        else
        {
            ans += s[i];
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}