class Solution {
public:
    bool subset_sum(vector<int>& arr,int sum,int n)
    {
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = true;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool opt1 = dp[i-1][j];
                bool opt2 = false;
                if(j>=arr[i-1])
                    opt2 = dp[i-1][j-arr[i-1]];
                dp[i][j] = opt1 || opt2;
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
            sum += i;
        if(sum%2!=0)
            return false;
        sum /= 2;
        return subset_sum(nums,sum,nums.size());
    }
};
