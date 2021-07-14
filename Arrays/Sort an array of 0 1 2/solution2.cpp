class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>v(3,0);
        for(auto i:nums)
        {
            v[i]++;
        }
        int i;
        for(i=0;i<v[0];i++)
            nums[i] =0;
        for(int j=0;j<v[1];j++)
        {
            nums[i++]=1;
        }
        for(int j=0;j<v[2];j++)
            nums[i++]=2;
    }
};