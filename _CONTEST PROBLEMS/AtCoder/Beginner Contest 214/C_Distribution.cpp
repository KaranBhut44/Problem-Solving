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
    cin>>n;
    int s[n]={0},t[n]={0};
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    int min_index=-1,min_val = INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        if(min_val > t[i])
        {
            min_val = t[i];
            min_index = i;
        }
    }
    ll ans[n];
    ans[min_index] = t[min_index];
    for(int i=min_index+1;i<n;i++)
    {
        ans[i] = min((ll)t[i], s[i-1] + ans[i-1]);
    }
    for(int i=0;i<min_index;i++)
    {
        ans[i] = min((ll)t[i], (i-1>=0?s[i-1]:s[n-1])+(i-1>=0?ans[i-1]:ans[n-1]) );
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
    return 0;
}
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
    cin>>n;
    int s[n]={0},t[n]={0};
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    int min_index=-1,min_val = INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        if(min_val > t[i])
        {
            min_val = t[i];
            min_index = i;
        }
    }
    ll ans[n];
    ans[min_index] = t[min_index];
    for(int i=min_index+1;i<n;i++)
    {
        ans[i] = min((ll)t[i], s[i-1] + ans[i-1]);
    }
    for(int i=0;i<min_index;i++)
    {
        ans[i] = min((ll)t[i], (i-1>=0?s[i-1]:s[n-1])+(i-1>=0?ans[i-1]:ans[n-1]) );
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
    return 0;
}