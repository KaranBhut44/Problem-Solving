class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current=0,max1=0;
        for(auto i:nums)
        {
            if(i==1)
                current++;
            else
            {
                max1 = max(max1,current);
                current=0;
            }
        }
        max1 = max(max1,current);
        return max1;
    }
};