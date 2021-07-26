#include<bits/stdc++.h>
#define ll long long
using namespace std;
void build1(ll *arr,ll *seg,ll l,ll r,ll index)
{   
    if(l == r) // leaf node
    {
        seg[index] = (arr[l]%2==0?1:0);
        return;
    }
    ll mid = (l+r)/2;
    build1(arr,seg,l,mid,index*2+1);
    build1(arr,seg,mid+1,r,index*2+2);
    seg[index] = seg[index*2 + 1] + seg[index*2+2];
}
void update(ll *seg,ll *arr,ll index,ll val,ll l,ll r,ll ind)
{
    if(l == r)
    {
        seg[index] = (val%2==0?1:0);
        return;
    }
    ll mid = (l+r)/2;
    if(ind <= mid)
        update(seg,arr,index*2+1,val,l,mid,ind);
    else
        update(seg,arr,index*2+2,val,mid+1,r,ind);
 
    seg[index] = seg[index*2 + 1] + seg[index*2+2];
}
ll query(ll *seg,ll l,ll r,ll low,ll high,ll index)
{
    if(low<=l && r<=high)
        return seg[index];
    if(high < l || low > r)
        return 0;
    ll mid = (l+r)/2;
    ll opt1 = query(seg,l,mid,low,high,index*2+1);
    ll opt2 = query(seg,mid+1,r,low,high,index*2+2);
    return opt1 + opt2;
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
    ll arr[n];
    ll seg[4*n] = {0};
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build1(arr,seg,0,n-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 0)
        {
            int x,y;
            cin>>x>>y;
            update(seg,arr,0,y,0,n-1,x-1);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            if(type == 1)
            {
                cout<<query(seg,0,n-1,l-1,r-1,0)<<endl;
            }
            else
            {
                cout<<r-l+1-query(seg,0,n-1,l-1,r-1,0)<<endl;
            }
        }
    }
}