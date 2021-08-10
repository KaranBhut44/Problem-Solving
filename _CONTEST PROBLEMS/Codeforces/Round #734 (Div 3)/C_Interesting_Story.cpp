#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<int,string> &p1,pair<int,string> &p2)
{
    return p1.first>p2.first;
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
        int n;
        cin>>n;
        vector<string>v;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        int max1 =-1;
        for(int index=0;index<5;index++)
        {
            vector<pair<int,string>>v1;
            for(auto str:v)
            {
                int p=0,n=0;
                for(auto i:str)
                {
                    if(i-'a' == index)
                        p++;
                    else
                        n++;
                }
                v1.push_back({p-n,str});
            }
            sort(v1.begin(),v1.end(),comp);
            int total=0,count=0;
            for(auto i:v1)
            {
                total += i.first;
                if(total > 0)
                    count++;
                else
                    break;
            }
            max1 = max(count,max1);
        }
        cout<<max1<<endl;
    }
    return 0;
}