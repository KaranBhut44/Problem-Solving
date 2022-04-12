class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        int second_last = last;
        for(int i=n-2;i>=0;i--)
        {
            int dontpick = second_last;
            int pick = nums[i];
            if(i+2 < n)
                pick += last;
            last = second_last;
            second_last = max(pick,dontpick);
        }
        return second_last;
    }
};
