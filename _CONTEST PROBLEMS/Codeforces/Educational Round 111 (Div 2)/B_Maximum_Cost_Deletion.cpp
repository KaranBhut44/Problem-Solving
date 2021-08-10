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
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        char prev = s[0];
        int count0=0,count1=0;
        if(prev == '0')
            count0++;
        else
            count1++;
        for(int i=1;i<n;i++)
        {
            if(prev != s[i])
            {
                if(s[i] == '0')
                    count0++;
                else
                    count1++;
                prev = s[i];
            }
        }
        
        int min_steps = min(count0,count1)+1;
        //cout<<count0<<" "<<count1<<" "<<min_steps<<endl;
        if(b>=0)
            cout<<(a+b)*n<<endl;
        else
            cout<<a*n + b*min_steps<<endl;
    }
    return 0;
}