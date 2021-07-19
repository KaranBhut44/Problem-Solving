class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int current = nums[0],max1 = nums[0];
        for(int i=1;i<n;i++)
        {
            if(current<0)
                current = 0;
            current += nums[i];
            max1 = max(current,max1);
            
        }
        return max1;
    }
};