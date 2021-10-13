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
        priority_queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            q.push({arr[i],i});
        }
        vector<pair<int,int>>v;
        int count;
        while(!q.empty())
        {
            pair<int,int>p1 = q.top();
            q.pop();
            if(q.empty())
                break;
            pair<int,int>p2 = q.top();
            q.pop();
            p1.first-=1;
            p2.first-=1;
            if(p2.first>=0)
                v.push_back({p1.second,p2.second});
            if(p1.first>0)
            {
                q.push(p1);
            }
            if(p2.first>0)
                q.push(p2);
        }
        count = v.size();
        cout<<count<<endl;
        for(auto i:v)
            cout<<min(i.first,i.second)+1<<" "<<max(i.first,i.second)+1<<endl;
    }

    
    return 0;
}