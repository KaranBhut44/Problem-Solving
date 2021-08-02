class Solution {
public:
    int max1 =0;
    int find(TreeNode *root)
    {
        if(root == nullptr)
            return -1;
        int ans1 = 1 + find(root->left);
        int ans2 = 1 + find(root->right);
        
        max1 = max(max1,ans1+ans2);
        return max(ans1,ans2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        find(root);
        return max1;
    }
};