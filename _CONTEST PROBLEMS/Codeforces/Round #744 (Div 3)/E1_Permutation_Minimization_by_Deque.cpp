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
        int n;
        cin>>n;
        deque<int>d;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            if(d.empty())
                d.push_back(temp);
            else
            {
                int curr = d.front();
                if(curr > temp)
                    d.push_front(temp);
                else
                    d.push_back(temp);
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<d[i]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}