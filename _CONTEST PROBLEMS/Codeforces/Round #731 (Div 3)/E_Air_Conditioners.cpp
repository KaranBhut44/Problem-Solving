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
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[m];
        ll a[n];
        for(int i=0;i<n;i++)
            a[i] = INT_MAX;
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>a[arr[i]-1];
        }
        ll temp = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i] > temp)
            {
                a[i] = temp;
                temp++;
            }
            else
                temp = a[i]+1;
        }
        temp = INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i] > temp)
            {
                a[i] = temp;
                temp++;
            }
            else
                temp = a[i]+1;
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}