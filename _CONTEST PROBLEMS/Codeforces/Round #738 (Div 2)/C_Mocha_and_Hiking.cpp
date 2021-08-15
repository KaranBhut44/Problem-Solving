#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v1;
void DFS(vector<int> *v,int s,bool *visited,int n)
{
    visited[s] = true;
    v1.push_back(s);
    for(auto i:v[s])
    {
        if(visited[i] == false)
            DFS(v,i,visited,n);
    }
    for(int i=0;i<=n;i++)
    {
        if(visited[i] == false)
        {
            visited[s] = false;
            v1.pop_back();
            return;
        }
    }
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
        vector<int> v[n+1];
        for(int i=0;i<n-1;i++)
        {
            v[i].push_back(i+1);
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
            {
                v[i].push_back(n);
            }
            else
            {
                v[n].push_back(i);
            }
        }
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<i+1<<" : ";
        //     for(auto j:v[i])
        //     {
        //         cout<<j+1<<" ";
        //     }
        //     cout<<endl;
        // }

        bool *visited = new bool[n+1];
        for(int i=0;i<=n;i++)
        {
            visited[i] = false;
        }

        int count;
        int flag = 0;
        for(int i=0;i<=n;i++)
        {
            count = 0;
            v1.clear();
            DFS(v,i,visited,n);
            for(int i=0;i<=n;i++)
            {
                if(visited[i] == true)
                {
                    count++;
                }
                visited[i] = false;
            }
            if(count == n +1 && (int)v1.size() == n+1)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(auto i:v1)
            cout<<i+1<<" ";
        cout<<endl;
    }
    return 0;
}