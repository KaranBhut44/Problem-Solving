int isPossible(int val,vector<int>&v)
{
    int current = 0;
    int count = 0;
    for(auto i:v)
    {
        if(current + i > val)
        {
            count++;
            current = i;
        }
        else
            current += i;
    }
    if(current <= val)
    {
        count++;
    }
    return count;
}
int binary_search1(int a,int b,vector<int> &v,int B,int ans)
{
    
    if(b<a)
        return ans;
    int mid = (a+b)/2;
    int val = isPossible(mid,v);
    if(val > B)
        return binary_search1(mid+1,b,v,B,ans);
    else
        return binary_search1(a,mid-1,v,B,mid);
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(B>n)
        return -1;
    int min_ans = INT_MIN, max_ans = 0;
    for(auto i:A)
    {
        min_ans = max(min_ans,i);
        max_ans += i;
    }
    int ans = binary_search1(min_ans,max_ans,A,B,-1);
    return ans;
}