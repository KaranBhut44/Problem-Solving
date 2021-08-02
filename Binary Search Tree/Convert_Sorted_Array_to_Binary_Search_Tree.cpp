class Solution {
public:
    
    TreeNode* convert(int s,int e,vector<int>& nums)
    {
        if(s>e)
            return nullptr;
        int mid = (s+e)>>1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = convert(s,mid-1,nums);
        root->right = convert(mid+1,e,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(0,n-1,nums);
    }
};