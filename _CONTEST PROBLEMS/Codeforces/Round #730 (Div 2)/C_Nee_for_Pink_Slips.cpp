#include<bits/stdc++.h>
using namespace std;
long double find(long double c,long double m,long double p,long double v,long double count,vector<bool> &flag)
{
    
    long double opt=0;
    if(flag[0])
    {
        long double c1=c,v1=v,m1=m,p1=p;
        vector<bool> vec1 = flag;
        if(c1 <= v1 + 1e-9)
        {
            if(vec1[1] && vec1[2])
            {
                long double inc = c1/2.0;
                m1 += inc;
                p1 += inc;
            }
            else if(vec1[2])
                p1 += c1;
            c1 = 0;
            vec1[0] =false;
        }
        else
        {
            if(vec1[1] && vec1[2])
            {
                long double inc = v1/2.0;
                m1 += inc;
                p1 += inc;
            }
            else if(vec1[2])
                p1 += v1;
            c1 -= v1;
        }
        
        opt += c*find(c1,m1,p1,v1,count+1.0,vec1);
    }
    if(flag[1])
    {
        long double c1=c,v1=v,m1=m,p1=p;
        vector<bool> vec1 = flag;
        if(m1 <= v1 + 1e-9)
        {
            if(vec1[0] && vec1[2])
            {
                long double inc = m1/2.0;
                c1 += inc;
                p1 += inc;
            }
            else if(vec1[2])
                p1 += m1;
            m1 = 0;
            vec1[1] =false;
        }
        else
        {
            if(vec1[0] && vec1[2])
            {
                long double inc = v1/2.0;
                c1 += inc;
                p1 += inc;
            }
            else if(vec1[2])
                p1 += v1;
            m1 -= v1;
        }
        opt += m*find(c1,m1,p1,v1,count+1.0,vec1);
    }
    opt += count*p;
    return opt;
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
        long double c,m,p,v;
        cin>>c>>m>>p>>v;
        vector<bool> v1 = {true,true,true};
        cout<<fixed<<setprecision(12)<<find(c,m,p,v,1.0,v1)<<endl;
    }
    return 0;
}