class Solution {
public:
    int find_max(vector<int> &nums,int n)
    {
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
    int rob(vector<int>& nums) {
        int ans1 = 0,ans2 = 0;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp2.push_back(nums[i]);
            if(i!=n-1) temp1.push_back(nums[i]);
        }
        //exclude_last
        ans1 = find_max(temp1,n-1);
        //exclude first
        ans2 = find_max(temp2,n-1);
        //find_max
        return max(ans1,ans2);
    }
};
