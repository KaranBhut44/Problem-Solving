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
    seg[index] = min(seg[index*2+1],seg[index*2+2]);
}
void make_old_update(ll *upd,int index,int l,int r,ll *seg)
{
    if(upd[index] != 0)
    {
        seg[index] += upd[index];
        if(l!=r)
        {
            upd[index*2+1] += upd[index]; 
            upd[index*2+2] += upd[index]; 
        }
    }
    upd[index] = 0;
}
void inc_val(int *arr,ll *seg,ll *upd,int index,int l,int r,int low,int high,ll val)
{
    make_old_update(upd,index,l,r,seg);
    if(low <= l && r <= high)
    {
        seg[index] += val;
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
    seg[index] = min(seg[2*index+1],seg[2*index+2]);
}
ll query(ll *seg,ll *upd,int index,int l,int r,int low,int high)
{
    make_old_update(upd,index,l,r,seg);
    if(low <= l && r <= high)
        return seg[index];

    if(low > r || high < l)
        return INT_MAX;

    int mid = (l+r)/2;
    ll ans1 = query(seg,upd,index*2+1,l,mid,low,high);
    ll ans2 = query(seg,upd,index*2+2,mid+1,r,low,high);
    
    return min(ans1,ans2);
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
    ll seg[4*n] = {0};
    ll upd[4*n] = {0};
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build_tree(arr,seg,0,0,n-1);

    int q;
    cin>>q;
    string s;
    getline(cin,s);
    while(q--)
    {
        string s="";
        getline(cin,s);
        vector<int>v;
        string temp="";
        for(auto i:s)
        {
            if(i == ' ')
            {
                v.push_back(stoi(temp));
                temp="";
            }
            else
            {
                temp += i;
            }
        }
        v.push_back(stoi(temp));
        if((int)v.size() == 2)
        {
            if(v[0] > v[1])
            {
                cout<<min(query(seg,upd,0,0,n-1,v[0],n-1),query(seg,upd,0,0,n-1,0,v[1]))<<endl;
            }
            else
                cout<<query(seg,upd,0,0,n-1,v[0],v[1])<<endl;
        }
        else
        {   if(v[0]> v[1])
            {
                inc_val(arr,seg,upd,0,0,n-1,v[0],n-1,v[2]);
                inc_val(arr,seg,upd,0,0,n-1,0,v[1],v[2]);
            }
            else
                inc_val(arr,seg,upd,0,0,n-1,v[0],v[1],v[2]);
        }
    }
    return 0;
}