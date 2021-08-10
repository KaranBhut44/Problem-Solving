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
        int w,h;
        cin>>w>>h;
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int first_height = y2-y1, first_width = x2-x1;
        int second_height,second_width;
        cin>>second_width>>second_height;
        int flag = 0;
        if(first_height + second_height > h && first_width + second_width > w)
        {
            //cout<<"case1"<<endl;
            cout<<fixed<<setprecision(6)<<-1<<endl;
            continue;
        }
        else if(max(first_height,second_height) >= h && max(first_width, second_width) >= w)
        {
            //cout<<first_height<<" "<<second_height<<" "<<first_width<<" "<<second_width<<" "<<h<<" "<<w<<endl;
            //cout<<"case2"<<endl;
            cout<<fixed<<setprecision(6)<<-1<<endl;
            continue;
        }
        else if(first_height + second_height > h || first_width + second_width > w)
        {
            //cout<<"case3"<<endl;
            if(first_width + second_width > w && first_height + second_height > h)
                flag = 1;
            else if(first_width + second_width > w)
                flag = 2;
            else
                flag = 3;
        }
        int upper_space = h - y2;
        int lower_space = y1;
        int left_space = x1;
        int right_space = w - x2;
        //cout<<upper_space<<" "<<lower_space<<" "<<left_space<<" "<<right_space<<endl;
        if(max(upper_space,lower_space)>= second_height || max(left_space,right_space) >= second_width)
        {
            //cout<<"case4"<<endl;
            cout<<0.000000<<endl;
            continue;
        }
        if(lower_space >= upper_space)
        {
            double x,y;
            if(left_space >= right_space)
            {
                //cout<<"case5"<<endl;
                x = second_width-x1;
                y = second_height-y1;
                if(left_space == right_space && left_space==0)
                    x = INT_MAX; 
            }
            else
            {
                //cout<<"case6"<<endl;
                x = x2 - w + second_width;
                y = second_height-y1;
            }
            if(lower_space == upper_space && lower_space==0)
                y = INT_MAX;
            if(flag == 1)
                cout<<fixed<<setprecision(6)<<pow(abs(x)+ abs(y),0.5)<<endl;
            else if(flag == 2)
                cout<<fixed<<setprecision(6)<<y<<endl;
            else if(flag == 3)
                cout<<fixed<<setprecision(6)<<x<<endl;
            else
                cout<<min(abs(x),abs(y))<<endl;
        }
        else
        {
            double x,y;
            if(left_space >= right_space)
            {
                //cout<<"case7"<<endl;
                x = second_width-x1;
                y = y2 - h + second_height;
                if(left_space == right_space && left_space==0)
                    x = INT_MAX; 
            }
            else
            {
                //cout<<"case8"<<endl;
                x = x2 - w + second_width;
                y = y2 - h + second_height;
            }
            if(flag == 1)
                cout<<fixed<<setprecision(6)<<pow(abs(x)+ abs(y),0.5)<<endl;
            else if(flag == 2)
                cout<<fixed<<setprecision(6)<<y<<endl;
            else if(flag == 3)
                cout<<fixed<<setprecision(6)<<x<<endl;
            else
                cout<<fixed<<setprecision(6)<<min(abs(x),abs(y))<<endl;
        }
    }
    return 0;
}