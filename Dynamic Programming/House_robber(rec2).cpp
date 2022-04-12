class Solution {
public:
    int fun(vector<int> &nums,int index,int *dp)
    {
        int n = nums.size();
        int ans = 0;
        if(index == n)
            return 0;
        if(dp[index] > -1)
            return dp[index];
        if(index == n-1)
        {
            return dp[index] = nums[index];
        }
        ans = nums[index] + fun(nums,index+2,dp);
        ans = max(ans, fun(nums,index+1,dp));
        return dp[index] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int *dp = new int[n];
        for(int i=0;i<n;i++)
        {
            dp[i] = -1;
        }
        return fun(nums,0,dp);
    }
};
