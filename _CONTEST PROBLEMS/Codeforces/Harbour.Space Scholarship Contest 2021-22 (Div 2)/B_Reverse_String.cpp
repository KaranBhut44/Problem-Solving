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
    int p;
    cin>>p;
    while(p--)
    {
        string s,t;
        cin>>s>>t;
        int n = s.size();
        int m = t.size();
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string a = "";
                for(int k=i;k<=j;k++)
                    a+=s[k];
                ///cout<<a<<endl;
                int rem = m-(int)a.size();
                
                if(j >= rem)
                {
                    for(int k=j-1;k>=j-rem;k--)
                    {
                        //cout<<"char: "<<s[k]<<endl;
                        a+=s[k];
                    }
                    if(a == t)
                    {
                        
                        flag =1;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}