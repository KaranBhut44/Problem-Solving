#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("error.txt","w",stderr);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = s[i]-'a'+1;
    }
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        arr[i] += temp;
        temp = arr[i];
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l>1)
            cout<<arr[r-1] - arr[l-2]<<endl;
        else
            cout<<arr[r-1]<<endl;
    }

    return 0;
}