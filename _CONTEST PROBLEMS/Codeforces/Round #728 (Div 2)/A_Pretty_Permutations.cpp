#include<bits/stdc++.h>
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
        {
            arr[i] = i+1;
        }
        if(n%2==0)
        {
            for(int i=0;i<n-1;i++)
            {
                swap(arr[i],arr[i+1]);
                i++;
            } 
        }
        else{
            arr[0] = 2;
            arr[2] = 1;
            arr[1] = 3;
            for(int i=3;i<n-1;i++)
            {
                swap(arr[i],arr[i+1]);
                i++;
            }
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}