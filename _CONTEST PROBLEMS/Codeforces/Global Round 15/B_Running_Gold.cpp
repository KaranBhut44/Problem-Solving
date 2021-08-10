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
        int arr[n][5];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>arr[i][j];
            }
        }
        vector<int>winner;
        int index = 0;
        for(int i=0;i<5;i++)
        {
            winner.push_back(arr[0][i]);
        }
        for(int i=1;i<n;i++)
        {
            int count =0;
            for(int j=0;j<5;j++)
            {
                if(winner[j] < arr[i][j])
                    count++;
            }
            if(count<3)
            {
                winner.clear();
                index = i;
                for(int j=0;j<5;j++)
                {
                    winner.push_back(arr[i][j]);
                }
            }
        }
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            int count =0;
            for(int j=0;j<5;j++)
            {
                if(winner[j] <= arr[i][j])
                    count++;
            }
            if(count<3)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<-1<<endl;
        else
            cout<<index+1<<endl;
    }
    return 0;
}