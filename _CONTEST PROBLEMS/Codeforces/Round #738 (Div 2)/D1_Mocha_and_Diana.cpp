#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p1[1000];
int r1[1000];
int p2[1000];
int r2[1000];

int findPar(int node,int flag)
{
    if(flag == 1)
    {
        if(node == p1[node])
            return node;
        return p1[node] = findPar(p1[node],1);
    }
    if(node == p2[node])
        return node;
    return p2[node] = findPar(p2[node],2);
}
void union1(int u,int v,int flag)
{
    if(flag == 1)
    {
        u = findPar(u,1);
        v = findPar(v,1);
        if(r1[u] < r1[v])
        {
            p1[u] = v;
        }
        else if(r1[u] > r1[v])
        {
            p1[v] = u;
        }
        else
        {
            p1[v] = u;
            r1[u]++;
        }
    }
    else if(flag ==2)
    {
        u = findPar(u,2);
        v = findPar(v,2);
        if(r2[u] < r2[v])
        {
            p2[u] = v;
        }
        else if(r2[u] > r2[v])
        {
            p2[v] = u;
        }
        else
        {
            p2[v] = u;
            r2[u]++;
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
    int n,p,q;
    cin>>n>>p>>q;
    
    for(int i=0;i<n;i++)
    {
        p1[i] = i;
        p2[i] = i;
    }

    for(int i=0;i<p;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        union1(u,v,1);
    }
    for(int i=0;i<q;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        union1(u,v,2);
    }
    int count = 0;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x1 = findPar(i,1);
            int y1 = findPar(j,1);
            int x2 = findPar(i,2);
            int y2 = findPar(j,2);
            
            if(x1 != y1 && x2!=y2)
            {
                union1(i,j,1);
                union1(i,j,2);
                v.push_back({i,j});
                count++;
            }
        }
    }
    cout<<count<<endl;
    for(auto i:v)
        cout<<i.first+1<<" "<<i.second+1<<endl;

    return 0;
}