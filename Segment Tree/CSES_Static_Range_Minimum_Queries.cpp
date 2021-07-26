#include<bits/stdc++.h>
#define ll long long
using namespace std;
void build_segment_tree(int index,int *arr,int *seg,int l,int r)
{
    if(l == r)
    {
        seg[index] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build_segment_tree(index*2+1,arr,seg,l,mid);
    build_segment_tree(index*2+2,arr,seg,mid+1,r);
    seg[index] = min(seg[index*2+1],seg[index*2+2]);
}
int query(int index,int *seg,int l,int r,int low,int high)
{
    if(low <= l && r <= high)
        return seg[index];
    if(low>r || high<l)
        return INT_MAX;
    int mid = (l+r)/2;
    int opt1 = query(index*2+1,seg,l,mid,low,high);
    int opt2 = query(index*2+2,seg,mid+1,r,low,high);
    return min(opt1,opt2);
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
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int seg[4*n];
    for(int i=0;i<4*n;i++)
        seg[i] = INT_MAX;
    build_segment_tree(0,arr,seg,0,n-1);
 
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(0,seg,0,n-1,l-1,r-1)<<endl;
    }
    return 0;
}