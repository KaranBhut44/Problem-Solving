#include<bits/stdc++.h>
using namespace std;
bool possible(int index, string s)
{
    int n = s.size();
    int flag1 =-1,flag2= -1,flag3=-1;
    for(int i=0;i<index;i++)
    {
        if(s[i] == '1')
            flag1 = i;
        else if(s[i] == '2')
            flag2 = i;
        else
            flag3 = i;
    }
    if(flag1 != -1 && flag2!=-1 && flag3!=-1)
        return true;
    int last = 0;
    for(int i=index;i<n;i++)
    {
        if(flag1 == last)
            flag1 = -1;
        else if(flag2 == last)
            flag2 = -1;
        else if(flag3 == last)
            flag3 = -1;
        last++;
        if(s[i] == '1')
            flag1 = i;
        else if(s[i] == '2')
            flag2 = i;
        else
            flag3 = i;
        if(flag1 != -1 && flag2!=-1 && flag3!=-1)
            return true;
    }
    return false;
}
int binary_search(int s,int e,string str,int index)
{
    if(s>e)
        return index;
    int mid = (s + e)/2;
    if(possible(mid,str))
        return binary_search(s,mid-1,str,mid);
    return binary_search(mid+1,e,str,index);
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
        string s;
        cin>>s;
        int n = s.size();
        int index = binary_search(3,n,s,-1);
        if(index == -1)
            cout<<0<<endl;
        else
            cout<<index<<endl;
    }
    return 0;
}