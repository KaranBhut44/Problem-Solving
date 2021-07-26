#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
void build_tree(int *arr,int *seg,int index,int l,int r)
{
    if(l == r)
    {
        seg[index] = arr[l];
        return;
    }
    int mid = (l + r)/2;
    build_tree(arr,seg,2*index+1,l,mid);
    build_tree(arr,seg,index*2+2,mid+1,r);
    seg[index] = min(seg[2*index+1],seg[2*index+2]);
}
void update(int *arr,int *seg,int index,int node,int val,int l,int r)
{
    if(l == r)
    {
        arr[l] = val;
        seg[index] = val;
        return;
    }
    int mid = (l+r)/2;
    if(node <= mid) 
        update(arr,seg,index*2+1,node,val,l,mid);
    else
        update(arr,seg,index*2+2,node,val,mid+1,r);
    seg[index] = min(seg[index*2+1],seg[index*2+2]);
}
int query(int *seg,int index,int l,int r,int low,int high)
{
    if(low <= l && r <= high)
        return seg[index];
    else if(low > r || high<l)
        return INT_MAX;
    int mid = (l+r)>>1;
    int opt1 = query(seg,index*2+1,l,mid,low,high);
    int opt2 = query(seg,index*2+2,mid+1,r,low,high);
    return min(opt1,opt2);
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
    int n,q;
    cin>>n>>q;
    int arr[n];
    rep(n)
        cin>>arr[i];
    int seg[4*n] = {0};
 
    build_tree(arr,seg,0,0,n-1);
 
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 1) //update
        {
            int node,val;
            cin>>node>>val;
            update(arr,seg,0,node-1,val,0,n-1);
        }
        else //query
        {
            int low,high;
            cin>>low>>high;
            cout<<query(seg,0,0,n-1,low-1,high-1)<<endl;
        }
    }
    return 0;
}