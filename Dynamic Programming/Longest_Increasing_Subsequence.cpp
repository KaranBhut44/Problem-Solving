class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int *op = new int[nums.size()];
        op[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            op[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]>=nums[i])
                    continue;
                int poss = op[j]+1;
                if(poss>op[i])
                    op[i]=poss;
            }
        }
        int best = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(best<op[i])
                best=op[i];
        }
        delete [] op;
        return best;
    }
};