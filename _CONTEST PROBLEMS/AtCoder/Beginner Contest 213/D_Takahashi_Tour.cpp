#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v;
void DFS(vector<int> *arr,int index,bool *visited)
{
    visited[index] = true;
    v.push_back(index);
    for(auto i:arr[index])
    {
        if(visited[i] == false)
        {
            DFS(arr,i,visited);
            v.push_back(index);
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
    int n;
    cin>>n;
    vector<int> arr[n];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i= 0;i<n;i++)
    {
        sort(arr[i].begin(),arr[i].end());
    }
    bool visited[n] = {false};
    DFS(arr,0,visited);
    for(auto i:v)
        cout<<i+1<<" ";
    return 0;
}