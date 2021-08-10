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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int count = 2*n -1;
        for(int i=0;i<n-2;i++)
        {
            if(!((arr[i] <= arr[i+1] && arr[i+1] <= arr[i+2]) 
            || (arr[i] >= arr[i+1] && arr[i+1] >= arr[i+2])))
            {
                count++;
            }
        }
        for(int i=0;i<n-3;i++)
        {
            if(!((arr[i] <= arr[i+1] && arr[i+1] <= arr[i+2]) 
            || (arr[i] >= arr[i+1] && arr[i+1] >= arr[i+2]) 
            || (arr[i] <= arr[i+2] && arr[i+2] <= arr[i+3]) 
            || (arr[i] >= arr[i+2] && arr[i+2] >= arr[i+3])
            || (arr[i] <= arr[i+1] && arr[i+1] <= arr[i+3]) 
            || (arr[i] >= arr[i+1] && arr[i+1] >= arr[i+3])
            || (arr[i+1] <= arr[i+2] && arr[i+2] <= arr[i+3]) 
            || (arr[i+1] >= arr[i+2] && arr[i+2] >= arr[i+3])))
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}