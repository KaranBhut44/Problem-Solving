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
        int n,m;
        cin>>n>>m;
        vector<string>v;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        int arr1[m][26]={0};
        for(auto i:v)
        {
            for(int j=0;j<m;j++) //i is string,j is char
            {
                arr1[j][i[j]-'a']+=1;
            }
        }
        v.clear();
        for(int i=0;i<n-1;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        for(auto i:v)
        {
            for(int j=0;j<m;j++) //i is string,j is char
            {
                arr1[j][i[j]-'a']-=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(arr1[i][j] == 1)
                {
                    cout<<(char)('a'+j);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}