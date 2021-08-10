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
        int h,w;
        cin>>h>>w;
        int arr[h][w];
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                arr[i][j] = 0;
            }
        }
        for(int i=0;i<w;i++)
        {
            if(i%2 == 0)
                arr[0][i] = 1;
        }
        for(int i=0;i<w;i++)
        {
            if(i%2 == 0)
                arr[h-1][i] = 1;
        }
        for(int i=0;i<h;i++)
        {
            if(i%2 == 0)
                arr[i][0] = 1;
        }
        for(int i=0;i<h;i++)
        {
            if(i%2 == 0)
                arr[i][w-1] = 1;
        }
        for(int i=1;i<h;i++)
        {
            if(arr[i-1][0] == 1)
                arr[i][0] = 0;
        }
        for(int i=1;i<h;i++)
        {
            if(arr[i-1][w-1] == 1)
                arr[i][w-1] = 0;
        }
        for(int i=1;i<w;i++)
        {
            if(arr[0][i-1] == 1)
                arr[0][i] = 0;
        }
        for(int i=1;i<w;i++)
        {
            if(arr[h-1][i-1] == 1)
                arr[h-1][i] = 0;
        }

        if(h>=2 && w>=2 && arr[h-1][w-2] && arr[h-2][w-1])
        {
            arr[h-1][w-2] = 0;
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}