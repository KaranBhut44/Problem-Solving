#include<bits/stdc++.h>
#define ll long long
using namespace std;
void leftshift(int l,int r,int *v)
{
    int temp = v[r];
    for(int i=r-1;i>=l;i--)
    {
        v[i+1] = v[i];
    }
    v[l] = temp;
}
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
            cin>>arr[i];
        }
        int arr1[n];
        for(int i=0;i<n;i++)
        {
            arr1[i] = arr[i];
        }
        sort(arr1,arr1+n);
        vector<vector<int>>v;
        int total = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == arr1[i])
                continue;
            total++;
            int ele = arr1[i];
            int left = i;
            int right = -1;
            int count = 0;
            for(int j=i+1;j<n;j++)
            {
                if(ele == arr[j])
                {
                    right = j;
                    break;
                }
                count++;
            }
            vector<int> v1 = {left,right,count};
            leftshift(left,right,arr);
            v.push_back(v1);
        }
        cout<<total<<endl;
        for(auto i:v)
        {
            for(auto j:i)
                cout<<j+1<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}