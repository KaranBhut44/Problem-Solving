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
        vector<int>v;
        for(auto i:s)
        {
            v.push_back(i-'a');
        }
        int temp = v[0];
        int n = v.size();
        int flag = 0;
        bool status = true;
        for(int i=1;i<n;i++)
        {
            if(temp > v[i])
            {
                if(flag==1)
                {
                    status = false;
                    break;
                }
            }
            else if(temp < v[i])
            {
                if(flag == 0)
                    flag = 1;
            }
            else
            {
                status = false;
                break;
            }
            temp = v[i];
        }
        sort(v.begin(),v.end());
        int count = 0;
        for(auto i:v)
        {
            if(i!=count)
            {
                status = false;
                break;
            }
            count++;
        }
        if(status)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}