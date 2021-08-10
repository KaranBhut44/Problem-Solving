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
        ll sum1 = 0;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            sum1 += temp;
        }
        ll avg1 = sum1 / n;
        ll count_1 = sum1 - avg1*n;
        cout<<count_1*(n-count_1)<<endl;
    }
    return 0;
}
