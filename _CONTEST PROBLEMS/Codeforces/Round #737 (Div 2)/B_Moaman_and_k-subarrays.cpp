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
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int dummy[n];
        for(int i=0;i<n;i++)
            dummy[i] = arr[i];
        sort(dummy,dummy+n);
        unordered_map<int,int>m;
        for(int i=0;i<n-1;i++)
        {
            m[dummy[i]] = dummy[i+1];
        }
        int flag = dummy[n-1];
        int count = 0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1] != m[arr[i]] || flag == arr[i])
                count++;
        }
        if(count+1 <= k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}