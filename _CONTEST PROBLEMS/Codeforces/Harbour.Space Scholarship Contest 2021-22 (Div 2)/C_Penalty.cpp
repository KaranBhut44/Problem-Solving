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
        string s;
        cin>>s;
        int a = 5;
        int b = 5;
        int n = 10;
        int index = 0;
        int score1 = 0;
        int score2 = 0;
        int flag = 0;
        while(index < n)
        {
            if(s[index] == '1')
            {
                if(index%2!=0)
                {
                    score2++;
                    b--;
                }
                else
                {
                    score1++;
                    a--;
                }
            }
            else if(s[index] == '0')
            {
                if(index%2!=0)
                    b--;
                else
                    a--;
            }
            else
            {
                if(index%2==0)
                {
                    a--;
                    score1++;
                }
                else
                    b--;
            }
            index++;
            if(score1-score2 > b || score2-score1>a)
            {
                break;
            }
            
        }
        int ans1 = index;
        a = 5;
        b = 5;
        n = 10;
        index = 0;
        score1 = 0;
        score2 = 0;
        flag = 0;
        while(index < n)
        {
            if(s[index] == '1')
            {
                if(index%2!=0)
                {
                    score2++;
                    b--;
                }
                else
                {
                    score1++;
                    a--;
                }
            }
            else if(s[index] == '0')
            {
                if(index%2!=0)
                    b--;
                else
                    a--;
            }
            else
            {
                if(index%2==0)
                {
                    a--;
                }
                else
                {
                    b--;
                    score2++;
                }
            }
            index++;
            if(score1-score2 > b || score2-score1>a)
            {
                break;
            }
            
        }
        cout<<min(ans1,index)<<endl;
    }
    return 0;
}


