class Solution {
public:
    void find_subseq(vector<int>& nums,vector<vector<int>>& ans,vector<int> curr,int n,int index)
    {
        if(index == n)
            return;
        vector<int> temp = curr;
        
        temp.push_back(nums[index]);
        ans.push_back(temp);
        find_subseq(nums,ans,curr,n,index+1);
        find_subseq(nums,ans,temp,n,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        int index = 0;
        ans.push_back(curr);
        find_subseq(nums,ans,curr,n,index);
        return ans;
    }
};