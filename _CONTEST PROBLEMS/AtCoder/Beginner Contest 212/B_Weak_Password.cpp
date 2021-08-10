#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;
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
    char p = s[0];
    int flag = 0;
    for(auto i:s)
    {
        if(i != s[0])
        {
            flag =1;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"Weak";
        return 0;
    }
    flag = 0;
    for(int i=1;i<4;i++)
    {
        if(s[i-1] == '9' && s[i] != '0')
        {
            flag = 1;
            break;
        }
        else if(s[i-1]!='9' && s[i-1]+ 1 != s[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        cout<<"Strong";
        return 0;
    }
    cout<<"Weak";
    return 0;
 
}