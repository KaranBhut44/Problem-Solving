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
        double sum = 0;
        int max1 = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            max1 = max(max1,temp);
            sum += temp;
        }
        sum -= max1;
        cout<<fixed<<setprecision(8)<<max1 + sum/(n-1)<<endl;
    }
    return 0;
}