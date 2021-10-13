#include<bits/stdc++.h>
#define ll long long
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
        int a,b;
        cin>>a>>b;
        int ans = 0;
        if(a%4 == 0)
            ans = 0;
        else
        {
            int ans1 = (a/4)*4;
            if(a%4 == 1)
            {
                ans = ans1;
            }
            else if(a%4 == 2)
            {
                ans = 1;
            }
            if(a%4 == 3)
            {
                ans = 1^(ans1+2);
            }
        }
        
        if(ans == b)
        {
            cout<<a<<endl;
            continue;
        }
        int temp = ans^b;
        if(temp == a)
        {
            cout<<a+2<<endl;
            continue;
        }
        cout<<a+1<<endl;
    }
    
    return 0;
}