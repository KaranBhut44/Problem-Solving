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
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    for(int j=0;j<m;j++)
        cin>>arr2[j];
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int diff = INT_MAX;
    int i=0,j=0;
    while(i<n && j<m)
    {
        diff = min(diff,abs(arr1[i]-arr2[j]));
        if(arr1[i] < arr2[j])
        {
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    while(i<n)
    {
        diff = min(diff,abs(arr1[i]-arr2[j-1]));
        i++;
    }
    while(j<m)
    {
        diff = min(diff,abs(arr1[i-1]-arr2[j]));
        j++;
    }
    cout<<diff;
    return 0;
 
}