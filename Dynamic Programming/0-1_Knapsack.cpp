int check(vector<int> &A, vector<int> &B, int C,int n,int index,int **dp)
{
    if(n==0 || C<=0)
        return 0;
    if(dp[C][n]>-1)
        return dp[C][n];
    int max1 = check(A,B,C,n-1,index+1,dp); 
    if(B[index] <= C)
    {
        max1 = max(max1, A[index] + check(A,B,C-B[index],n-1,index+1,dp));
    }
    dp[C][n] = max1;
    return max1;
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    int **dp = new int*[C+1];
    for(int i=0;i<=C;i++)
    {
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++)
            dp[i][j] = -1;
    }
    return check(A,B,C,n,0,dp);
}
