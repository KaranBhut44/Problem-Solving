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
        string s;
        cin>>s;
        int l = s.size();
        if(l==1 && s[0]=='0')
        {
            cout<<0<<endl;
            continue;
        }
        string  a;
        a += s[l-2];
        a += s[l-1];
        int last = stoi(a);
        if(last == 0 || last == 25 || last == 50 || last== 75)
        {
            cout<<0<<endl;
            continue;
        }
        int last5 = 0;
        int last0 = 0;
        int flag5 = 0,flag0 = 0;
        for(int i= l-1;i>=0;i--)
        {
            if(flag5 == 0 && s[i] == '5')
            {
                last5 = i;
                flag5 = 1;
            }
            else if(flag0 == 0 && s[i] == '0')
            {
                last0 = i;
                flag0 = 1;
            }
        }
        int sum1 = INT_MAX,sum2 =INT_MAX;
        if(flag5 == 1)
        {
            sum1 = 0;
            int first = l-1-last5;
            sum1 += first;

            int sec = -1;
            for(int i= last5-1;i>=0;i--)
            {
                if(s[i]=='2' || s[i]=='7')
                {
                    sec = i;
                    break;
                }
            }
            if(sec == -1)
            {
                sum1 = INT_MAX;
            }
            else
            {
                int second = last5-sec-1;
                sum1 += second;
            }
            
        }
        if(flag0 == 1)
        {
            sum2 = 0;
            int first = l-1-last0;
            sum2 += first;

            int sec = -1;
            for(int i= last0-1;i>=0;i--)
            {
                if(s[i]=='5' || s[i]=='0')
                {
                    sec = i;
                    break;
                }
            }
            if(sec == -1)
            {
                sum2 = INT_MAX;
            }
            else
            {
                int second = last0-sec-1;
                sum2 += second;
            }
            
        }
        cout<<min(sum1,sum2)<<endl;    
    }
    return 0;
}