#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    string s;
    cin>>s;
    int n = s.size();
    vector<pair<int,ll>> arr[8];
    for(int i=0 ; i<n ;i++)
    {
        if(s[i] == 'c')
            arr[0].emplace_back(i,0);
        else if(s[i] == 'h')
            arr[1].emplace_back(i,0);
        else if(s[i] == 'o')
            arr[2].emplace_back(i,0);
        else if(s[i] == 'k')
            arr[3].emplace_back(i,0);
        else if(s[i] == 'u')
            arr[4].emplace_back(i,0);
        else if(s[i] == 'd')
            arr[5].emplace_back(i,0);
        else if(s[i] == 'a')
            arr[6].emplace_back(i,0);
        else if(s[i] == 'i')
            arr[7].emplace_back(i,1);
    }
    ll count=1;
    int m = arr[7].size();
    for(int i=m-1;i>=0;i--)
    {
        arr[7][i].second = count++;
    }
    for(int i=6;i>=0;i--)
    {
        int m = arr[i].size();
        int flag = 0;
        for(int j = m-1;j>=0;j--)
        {
            int sz = arr[i+1].size();
            int index = lower_bound(arr[i+1].begin(),arr[i+1].end(),arr[i][j]) - arr[i+1].begin();
            if(index == sz)
            {
                continue;
            }
            flag = 1;
            ll sum1 = arr[i+1][index].second;
            sum1 = (sum1 + (j==m-1?0:arr[i][j+1].second))%mod;
            arr[i][j].second = sum1;
        }
        if(flag == 0)
        {
            cout<<0;
            return 0;
        }
    }
    cout<<arr[0][0].second%mod;
    return 0;
}