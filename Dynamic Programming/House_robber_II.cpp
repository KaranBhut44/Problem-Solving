class Solution {
public:
    int rob(vector<int>& nums) {
        int ans1 = 0,ans2 = 0;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        //exclude_last 
        int last = nums[n-2];
        int second_last = last;
        for(int i=n-3;i>=0;i--)
        {
            int dontpick = second_last;
            int pick = nums[i];
            if(i+2 < n-1)
                pick += last;
            last = second_last;
            second_last = max(pick,dontpick);
        }
        ans1 = second_last;
        //exclude first
        last = nums[n-1];
        second_last = last;
        for(int i=n-2;i>0;i--)
        {
            int dontpick = second_last;
            int pick = nums[i];
            if(i+2 < n)
                pick += last;
            last = second_last;
            second_last = max(pick,dontpick);
        }
        ans2 = second_last;
        //find_max
        return max(ans1,ans2);
    }
};
