class Solution {
public:
    int fun(vector<int> &nums,int flag,int index,int **dp)
    {
        int n = nums.size();
        int ans = 0;
        if(dp[index][flag] > -1)
            return dp[index][flag];
        if(index == n-1)
        {
            if(flag)
                return dp[index][flag] = 0;
            return dp[index][flag] = nums[index];
        }
        if(flag == 0)
        {
            ans = nums[index] + fun(nums,1,index+1,dp);
        }
        ans = max(ans, fun(nums,0,index+1,dp));
        return dp[index][flag] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int **dp = new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i] = new int[2];
            for(int j=0;j<2;j++)
                dp[i][j] = -1;
        }
        return fun(nums,0,0,dp);
    }
};
