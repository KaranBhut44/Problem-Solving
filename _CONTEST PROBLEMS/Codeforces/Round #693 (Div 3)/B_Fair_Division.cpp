#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int one=0,two=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a==1)
                one++;
            else
                two++;
        }
        if(one%2==0 && two%2==0)
        {
            cout<<"YES"<<endl;
        }
        else if(one%2==0)
        {
            if(one>=2)
                cout<<"YES"<<endl;
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else if(two%2==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}