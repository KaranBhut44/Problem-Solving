#include<bits/stdc++.h>
using namespace std;

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
        string a,b;
        cin>>a>>b;
        int i = a.size()-1;
        int j = b.size()-1;
        while(i>=0 && j>=0)
        {
            if(a[i] == b[j])
            {
                i--;
                j--;
            }
            else
                i-=2;
        }
        if(j == -1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}