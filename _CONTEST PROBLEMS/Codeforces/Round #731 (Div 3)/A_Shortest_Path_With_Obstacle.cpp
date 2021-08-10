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
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        int res=0;
        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
        if(x1==x2 || y1==y2)
        {
            if(x1==x2 && x2==x3 && ((y1<y3 && y3<y2) || (y2<y3 && y3<y1)))
            {
                res = abs(y1-y2) + 2;
            }
            else if(y1==y2 && y2==y3 && ((x1<x3 && x3<x2) || (x2<x3 && x3<x1)))
            {
                res = abs(x1-x2) + 2;
            }
            else
            {
                res = abs(x1-x2) + abs(y1-y2);
            }
        }
        else
        {
            res = abs(x1-x2) + abs(y1-y2);
        }
        cout<<res<<endl;
    }
    return 0;
}
