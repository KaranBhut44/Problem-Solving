#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<int,int> p1,pair<int,int>p2)
{
    return p1.first<p2.first;
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
    int h,w,n;
    cin>>h>>w>>n;
    pair<int,int> arr_x[n],arr_y[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr_x[i] = {x,i};
        arr_y[i] = {y,i};
    }
    
    sort(arr_x,arr_x+n,comp);
    sort(arr_y,arr_y+n,comp);
 
    int a_x[n],a_y[n];
    int j1 = 0,j2 = 0;
    int prev1 = -11,prev2 = -11;
    for(int i=0;i<n;i++)
    {
        if(prev1 != arr_x[i].first)
            j1++;
        if(prev2 != arr_y[i].first)
            j2++;
        a_x[arr_x[i].second] = j1;
        a_y[arr_y[i].second] = j2;
        prev1 = arr_x[i].first;
        prev2 = arr_y[i].first;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a_x[i]<<" "<<a_y[i]<<endl;
    }
    return 0;
}