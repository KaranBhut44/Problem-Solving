class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        
        int prev = nums[0];
        int index=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=prev)
            {
                nums[index] = nums[i];
                prev = nums[i];
                index++;
            }
        }
        return index;
    }
};