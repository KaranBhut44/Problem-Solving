#include<bits/stdc++.h>
int fun(int n, vector<vector<int>> &points,int **dp,int last)
{
	int max_val = INT_MIN;
	if(n == 0)
	{
		for(int task=0;task<3;task++)
		{
			if(last != task)
			{
				max_val = max(max_val, points[n][task]);
			}
		}
		return max_val;
	}
	if(dp[n][last] > -1)
		return dp[n][last];
	for(int task=0;task<3;task++)
	{
		if(task!=last)
			max_val = max(max_val,points[n][task] + fun(n-1,points,dp,task));
	}
	return dp[n][last] = max_val;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	int **dp = new int*[n];
	for(int i=0;i<n;i++)
	{
		dp[i] = new int[4];
		for(int j=0;j<4;j++)
		{
			dp[i][j] = -1;
		}
	}
	return fun(n-1,points,dp,3);
}
