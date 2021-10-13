#include<bits/stdc++.h>
#define ll long long
using namespace std;
int countleft(char **arr,int i,int j,int n,int m)
{
    
    int count =-1;
    while(i >=0 && j>=0 && arr[i][j] == '*')
    {
        count++;
        i--;
        j--;
    }
    return count;
}
int countright(char **arr,int i,int j,int n,int m)
{
    int count = -1;
    while(i >=0 && j<m && arr[i][j] == '*')
    {
        count++;
        i--;
        j++;
    }
    return count;
}
void mark_flag(bool **flag,int val,int i,int j)
{
    int x = i,y = j;
    if(val == 0)
        return;
    
    flag[i][j] = true;
    int val1 = val;
    while(val--)
    {
        i--;
        j--;
        flag[i][j] = true;
    }
    i = x;
    j = y;
    while(val1--)
    {
        i--;
        j++;
        flag[i][j] = true;
    }

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
        int n,m,k;
        cin>>n>>m>>k;
        char **arr = new char*[n];
        bool **flag = new bool*[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = new char[m];
            flag[i] = new bool[m];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
                flag[i][j] = false;
            }        
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(arr[i][j] == '*')
                {
                    
                    int left = countleft(arr,i,j,n,m);
                    int right = countright(arr,i,j,n,m);
                    int val = min(left,right);
                    if(val >= k)
                        mark_flag(flag,val,i,j);
                    // cout<<i<<" "<<j<<" "<<left<<" "<<right<<endl;
                }
            }
        }
        int no = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(arr[i][j] == '*' && flag[i][j] == false)
                {
                    no = 1;
                    break;
                }
            }
            if(no == 1)
                break;
        }
        if(no)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

    }
    
    return 0;
}