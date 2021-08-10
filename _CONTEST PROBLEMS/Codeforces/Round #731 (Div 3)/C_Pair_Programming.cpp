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
        int k,n,m;
        cin>>k>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        int i=0,j=0;
        vector<int>v;
        bool flag = true;
        while(i<n && j<m)
        {
            if(a[i] == 0)
            {
                k++;
                i++;
                v.push_back(0);
            }
            else if(b[j] == 0)
            {
                k++;
                j++;
                v.push_back(0);
            }
            else if(a[i] <= b[j])
            {
                if(a[i] > k)
                {
                    flag = false;
                    break;
                }
                else
                {
                    v.push_back(a[i]);
                    i++;
                }
            }
            else{
                if(b[j] > k)
                {
                    flag = false;
                    break;
                }
                else
                {
                    v.push_back(b[j]);
                    j++;
                }
            }
        }
        while(i<n)
        {
            if(a[i] == 0)
            {
                k++;
                v.push_back(0);
            }
            else if(a[i] > k)
            {
                flag = false;
                break;
            }
            else
            {
                v.push_back(a[i]);
            }
            i++;
        }
        while(j<m)
        {
            if(b[j] == 0)
            {
                k++;
                v.push_back(0);
            }
            else if(b[j] > k)
            {
                flag = false;
                break;
            }
            else
            {
                v.push_back(b[j]);
            }
            j++;
        }
        if(flag)
        {
            for(auto i:v)
                cout<<i<<" ";
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}