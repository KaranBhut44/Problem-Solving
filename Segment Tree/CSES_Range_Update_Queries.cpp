#include<bits/stdc++.h>
#define ll long long
using namespace std;
void build_tree(int *arr,ll *seg,int index,int l,int r)
{
    if(l == r)
    {
        seg[index] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build_tree(arr,seg,index*2+1,l,mid);
    build_tree(arr,seg,index*2+2,mid+1,r);
    seg[index] = seg[index*2+1] + seg[index*2+2];
}
void inc_val(int *arr,ll *seg,ll *upd,int index,int l,int r,int low,int high,ll val)
{
    if(upd[index] > 0)
    {
        seg[index] += upd[index];
        if(l!=r)
        {
            upd[index*2+1] += upd[index]; 
            upd[index*2+2] += upd[index]; 
        }
        upd[index] = 0;
    }
    if(low <= l && r <= high)
    {
        seg[index] += val*(r-l+1);
        if(l!=r)
        {
            upd[index*2+1] += val; 
            upd[index*2+2] += val; 
        }
        return;
    }
    if(low > r || high < l)
        return;
    int mid = (l+r)/2;
    inc_val(arr,seg,upd,index*2+1,l,mid,low,high,val);
    inc_val(arr,seg,upd,index*2+2,mid+1,r,low,high,val);
    seg[index] = seg[2*index+1] + seg[2*index+2];
}
ll query(ll *seg,ll *upd,int index,int l,int r,int low,int high)
{
    if(upd[index] > 0)
    {
        seg[index] += upd[index]*(r-l+1);
        if(l!=r)
        {
            upd[index*2+1] += upd[index]; 
            upd[index*2+2] += upd[index]; 
        }
        upd[index] = 0;
    }
    if(low <= l && r <= high)
        return seg[index];
 
    if(low > r || high < l)
        return 0;
 
    int mid = (l+r)/2;
    ll ans1 = query(seg,upd,index*2+1,l,mid,low,high);
    ll ans2 = query(seg,upd,index*2+2,mid+1,r,low,high);
    return ans1+ans2;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    int n,q;
    cin>>n>>q;
    int arr[n];
    ll seg[4*n] = {0};
    ll upd[4*n] = {0};
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build_tree(arr,seg,0,0,n-1);
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 1)
        {
            int low,high;
            ll val;
            cin>>low>>high>>val;
            inc_val(arr,seg,upd,0,0,n-1,low-1,high-1,val);
        }
        else
        {
            int k;
            cin>>k;
            cout<<query(seg,upd,0,0,n-1,k-1,k-1)<<endl;
        }
    }
    return 0;
}