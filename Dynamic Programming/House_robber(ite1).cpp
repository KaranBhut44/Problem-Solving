class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int *dp = new int[n];
        dp[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int dontpick = dp[i+1];
            int pick = nums[i];
            if(i+2 < n)
                pick += dp[i+2];
            dp[i] = max(pick,dontpick);
        }
        return dp[0];
    }
};
