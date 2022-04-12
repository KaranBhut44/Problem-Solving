#include<bits/stdc++.h>
int fun(int n, vector<vector<int>> &points,int **dp,int index)
{
	int max_val = INT_MIN;
	if(n < 0)
		return 0;
	if(dp[n][index] > -1)
		return dp[n][index];
	if(n == 0)
	{
		return dp[n][index] = points[n][index];
	}
	for(int i=0;i<3;i++)
	{
		if(i!=index)
			max_val = max(max_val,points[n][index] + fun(n-1,points,dp,i));
	}
	return dp[n][index] = max_val;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	int **dp = new int*[n];
	for(int i=0;i<n;i++)
	{
		dp[i] = new int[3];
		for(int j=0;j<3;j++)
		{
			dp[i][j] = -1;
		}
	}
	int a = fun(n-1,points,dp,0);
	int b = fun(n-1,points,dp,1);
	int c = fun(n-1,points,dp,2);
	return max(a,max(b,c));
}
