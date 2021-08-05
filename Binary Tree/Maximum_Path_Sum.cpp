class Solution {
public:
    int maxPath = INT_MIN;
    int traverse(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int left = max(0,traverse(root->left));
        int right = max(0,traverse(root->right));
        maxPath = max(maxPath, left + right + root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return maxPath;
    }
};