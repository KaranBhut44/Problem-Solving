class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i] > nums[i-1])
            {
                index = i-1;
                break;
            }
        }
        if(index == -1)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        
        int index2 = index+1;
        int ele = nums[index];
        for(int i=index+1;i<n;i++)
        {
            if(ele < nums[i] && nums[index2]>nums[i])
            {
                index2 = i;
            }
        }
        swap(nums[index],nums[index2]);
        sort(nums.begin()+index+1,nums.end());
    }
};