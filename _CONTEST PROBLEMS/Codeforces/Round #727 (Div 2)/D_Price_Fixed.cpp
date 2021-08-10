#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct s
{
    ll a,b;
};
bool comp(s &p1, s &p2)
{
    if(p1.b!=p2.b)
        return p1.b<p2.b;
    return p1.a<p2.a;
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

    int n;
    cin>>n;
    vector<s>v;
    for(int i=0;i<n;i++)
    {
        s s1;
        cin>>s1.a;
        cin>>s1.b;
        v.push_back(s1);
    }
    sort(v.begin(),v.end(),comp);
    int l=0,r=n-1;
    ll items = 0;
    ll sum1=0;
    // for(int i=l;i<=r;i++)
    //         cout<<v[i].a<<" "<<v[i].b<<" "<<endl;
    //     cout<<l<<" "<<r<<" "<<items<<" "<<sum1<<endl;
    //     cout<<"************************************************"<<endl;
    while(l<=r)
    {
        
        if(v[l].b<=items)
        {
            items += v[l].a;
            sum1 += v[l].a;
            l++;
        }
        else
        {
            if(v[r].a + items <= v[l].b)
            {
                items += v[r].a;
                sum1 += v[r].a*2;
                r--;
            }
            else
            {
                v[r].a -= (v[l].b-items);
                sum1 += (v[l].b-items)*2;
                items += (v[l].b-items);
            }
        }
        // for(int i=l;i<=r;i++)
        //     cout<<v[i].a<<" "<<v[i].b<<" "<<endl;
        // cout<<l<<" "<<r<<" "<<items<<" "<<sum1<<endl;
        // cout<<"************************************************"<<endl;
    }
    cout<<sum1;
    return 0;
}
