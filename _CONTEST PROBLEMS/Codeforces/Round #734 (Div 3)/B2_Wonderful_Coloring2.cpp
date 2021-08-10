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
        int m1,k;
        cin>>m1>>k;
        int arr[m1];
        for(int i=0;i<m1;i++)
            cin>>arr[i];

        unordered_map<int,vector<int>>m;
        for(int i=0;i<m1;i++)
            m[arr[i]].push_back(i);
        int n = m.size();
        int r =0,g=0;
        int arr2[m1] = {0};
        int count = 0;
        int ans[k] = {0};

        for(auto i:m)
        {   
            if((int)i.second.size()>=k)
            {
                vector<int>index = i.second;
                int ind = 0;
                for(int j=0;j<k;j++)
                {
                    arr2[index[j]] = j+1;
                }
            }
            else
            {
                vector<int>index = i.second;
                count = count%k;
                int sz = index.size();
                for(int j=0;j<sz;j++)
                {
                    count = count%k;
                    arr2[index[j]] = count+1;
                    count++;
                }
            }
        }
        int arr3[k] = {0};
        for(int i=0;i<m1;i++)
        {
            arr3[arr2[i]-1]++;
        }
        int min1 = INT_MAX;
        for(int i=0;i<k;i++)
        {
            min1 = min(min1,arr3[i]);
        }
        int arr4[k] ={0};
        for(int i=0;i<m1;i++)
        {
            arr4[arr2[i]-1]++; 
            if(arr4[arr2[i]-1] <= min1)
                cout<<arr2[i]<<" ";
            else
                cout<<0<<" ";
            
        }
        cout<<endl;
    }
    return 0;
}