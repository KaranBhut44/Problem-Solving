#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int O=0; // closing bracket
    int C=0; // opening bracket
    int F=0; // full bracket 
};
void build1(string &s,node *seg,ll l,ll r,ll index)
{  
    if(l == r)
    {
        if(s[l] == '(')
            seg[index].O = 1;
        else if(s[l] == ')')
            seg[index].C = 1;
        return;
    }
    ll mid = (l+r)/2;
    build1(s,seg,l,mid,index*2+1);
    build1(s,seg,mid+1,r,index*2+2);
    int new_F = min(seg[index*2 + 1].O,seg[index*2+2].C);
    seg[index].O =  seg[index*2+1].O-new_F;
    seg[index].C =  seg[index*2+2].C-new_F;
    seg[index].O += seg[index*2 + 2].O;
    seg[index].C += seg[index*2 + 1].C;
    seg[index].F = seg[index*2+1].F + seg[index*2+2].F + new_F;
}
node query(node *seg,ll l,ll r,ll low,ll high,ll index)
{
    if(low<=l && r<=high)
        return seg[index];
    node ans;
    if(high < l || low > r)
        return ans;
    ll mid = (l+r)/2;
    node opt1 = query(seg,l,mid,low,high,index*2+1);
    node opt2 = query(seg,mid+1,r,low,high,index*2+2);
    int new_F = min(opt1.O,opt2.C);
    ans.O =  opt1.O-new_F;
    ans.C =  opt2.C-new_F;
    ans.O += opt2.O;
    ans.C += opt1.C;
    ans.F = opt1.F + opt2.F + new_F;
    return ans;
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
    string s;
    cin>>s;
    int q;
    cin>>q;
    int n = s.size();
    node seg[4*n];
    build1(s,seg,0,n-1,0);
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<query(seg,0,n-1,l-1,r-1,0).F*2<<endl;
    }
    return 0;
}